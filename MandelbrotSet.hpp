//
// Created by fergus on 01/08/17.
//

#pragma once

#include <atomic>
#include <complex>
#include <iomanip>
#include <iostream>
#include <omp.h>
#include <sstream>

class MandelbrotSet
{
private:

    std::size_t mChunkSize;

public:

    explicit MandelbrotSet() = default;

    static void CalculateArea(unsigned npoints, unsigned max_iter, unsigned block_size=1)
    {

        std::atomic_size_t num_outside(0);
        auto npoints_f = static_cast<double>(npoints);

        #pragma omp parallel default(none) shared(npoints, npoints_f, max_iter, num_outside) num_threads(block_size)
        {
            std::complex<double> c;
            std::complex<double> z;

            #pragma omp master
            {
                for (auto i = 0; i < npoints; ++i)
                {
                    #pragma omp task firstprivate(i)
                    {
                        std::size_t local_outside = 0;
                        for (auto j = 0; j < npoints; ++j)
                        {
                            c.real(-2.0 + 2.5 * i / npoints_f + 1.0e-7);
                            c.imag(1.125 * j / npoints_f + 1.0e-7);
                            z = c;

                            for (auto it = 0; it < max_iter; ++it)
                            {
                                z = z * z + c;

                                if (std::norm(z) > 4.0e0)
                                {
                                    local_outside++;
                                    break;
                                }
                            }
                        }
                        num_outside += local_outside;
                    }
                }
            }
        }
        double area = 2.0 * 2.5 * 1.125 * (npoints_f * npoints_f - num_outside) / (npoints_f * npoints_f);
        double error = area / npoints_f;

        std::cout << std::setprecision(10) << "Area of Mandlebrot set = " << area << " +/- " << error << '\n';
    }
};