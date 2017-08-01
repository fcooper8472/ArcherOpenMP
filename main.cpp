
#include <iostream>
#include <omp.h>
#include <sstream>

#include "MandelbrotSet.hpp"

int main()
{
#pragma omp parallel default(none) shared(std::cout)
    {
        if(omp_get_thread_num() == 0)
        {
            std::stringstream num_threads;
            num_threads << "Using " << omp_get_num_threads() << " OpenMP threads" << std::endl;
            std::cout << num_threads.str();
        }
    }

    MandelbrotSet m;
    m.CalculateArea(2000u, 200u);
}
