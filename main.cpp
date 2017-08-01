
#include <chrono>
#include <iostream>
#include <omp.h>
#include <sstream>

#include "MandelbrotSet.hpp"

int main()
{
    using clock = std::chrono::high_resolution_clock;

#pragma omp parallel default(none) shared(std::cout)
    {
        if(omp_get_thread_num() == 0)
        {
            std::stringstream num_threads;
            num_threads << "Using " << omp_get_num_threads() << " OpenMP threads" << std::endl;
            std::cout << num_threads.str();
        }
    }

    auto t_start = clock::now();
    MandelbrotSet m;
    m.CalculateArea(2000u, 200u);
    auto t_end = clock::now();
    auto time_spent = std::chrono::duration_cast<std::chrono::duration<double>>(t_end - t_start);

    std::cout << "Time elapsed: " << time_spent.count() << " seconds" << std::endl;
}
