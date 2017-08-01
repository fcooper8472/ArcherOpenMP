//
// Created by fergus on 01/08/17.
//

#pragma once

#include <complex>
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
        std::cout << "--------------------------------\n";
        std::cout << "Mandlebrot: (" << npoints << "," << max_iter << ") with block size " << block_size << '\n';

        std::size_t num_outside = 0;

        auto npoints_f = static_cast<double>(npoints);
        std::complex<double> c;
        std::complex<double> z;

#pragma omp parallel for shared(npoints, npoints_f, max_iter) reduction(+:num_outside) private(c, z) schedule(static, block_size)
        for (auto i = 0 ; i < npoints ; ++i)
        {
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
                        num_outside++;
                        break;
                    }
                }
            }
        }

        double area = 2.0 * 2.5 * 1.125 * (npoints_f * npoints_f - num_outside) / (npoints_f * npoints_f);
        double error = area / npoints_f;

        std::cout << "Area of Mandlebrot set = " << area << " +/- " << error << '\n';
        std::cout << "--------------------------------\n";
    }
};