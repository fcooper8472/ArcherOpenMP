//
// Created by fergus on 01/08/17.
//

#include <complex>

class MandelbrotSet
{
private:

public:

    MandelbrotSet() = default;

    void CalculateArea(unsigned npoints, unsigned max_iter)
    {
        auto npoints_f = static_cast<double>(npoints);
        std::size_t num_outside = 0;

        std::complex<double> c;
        std::complex<double> z;

        for (auto i = 0; i < npoints; ++i)
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

        std::stringstream output;
        output << "Area of Mandlebrot set = " << area << " +/- " << error << std::endl;

        std::cout << output.str();
    }
};








//void calculate_area()
//{
//  int i, j, iter, numoutside = 0;
//  double area, error, ztemp;
//  struct complex z, c;
//
///*
// *
// *
// *     Outer loops run over npoints, initialise z=c
// *
// *     Inner loop has the iteration z=z*z+c, and threshold test
// */
//
//  for (i=0; i<NPOINTS; i++) {
//    for (j=0; j<NPOINTS; j++) {
//      c.real = -2.0+2.5*(double)(i)/(double)(NPOINTS)+1.0e-7;
//      c.imag = 1.125*(double)(j)/(double)(NPOINTS)+1.0e-7;
//      z=c;
//      for (iter=0; iter<MAXITER; iter++){
//        ztemp=(z.real*z.real)-(z.imag*z.imag)+c.real;
//        z.imag=z.real*z.imag*2+c.imag;
//        z.real=ztemp;
//        if ((z.real*z.real+z.imag*z.imag)>4.0e0) {
//          numoutside++;
//          break;
//        }
//      }
//    }
//  }
//
//
//
///*
// *  Calculate area and error and output the results
// */
//
//      area=2.0*2.5*1.125*(double)(NPOINTS*NPOINTS-numoutside)/(double)(NPOINTS*NPOINTS);
//      error=area/(double)NPOINTS;
//
//      printf("Area of Mandlebrot set = %12.8f +/- %12.8f\n",area,error);

//}
