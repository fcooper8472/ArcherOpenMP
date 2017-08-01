
#include <chrono>
#include <iostream>
#include <omp.h>
#include <sstream>

#include "MandelbrotSet.hpp"
#include "Timer.hpp"


int main()
{
    #pragma omp parallel default(none) shared(std::cout)
    {
        #pragma omp single
        std::cout << "Using " << omp_get_num_threads() << " OpenMP threads" << std::endl;
    }

    Timer timer;

    MandelbrotSet m{};

    std::initializer_list<unsigned> block_sizes = {1, 2, 4, 8, 16};

    for(auto&& block_size : block_sizes)
    {
        timer.PollTime();
        m.CalculateArea(4000u, 2000u, block_size);
        std::cout << "Time elapsed: " << timer.GetElapsedTime() << " seconds" << std::endl;
    }
}
