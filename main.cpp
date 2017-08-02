
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
        std::cout << "Using max " << omp_get_num_threads() << " OpenMP threads" << std::endl;
    }

    Timer timer;

    MandelbrotSet m{};

    std::initializer_list<unsigned> threads = {1, 2, 4, 8};

    for(auto&& thread : threads)
    {
        unsigned npoints = 4000;
        unsigned max_iter = 1000;

        std::cout << "--------------------------------\n";
        std::cout << "Mandlebrot: (" << npoints << "," << max_iter << ") with " << thread << " threads\n";

        timer.PollTime();
        m.CalculateArea(npoints, max_iter, thread);
        std::cout << "Time elapsed: " << timer.GetElapsedTime() << " seconds" << std::endl;
        std::cout << "--------------------------------\n";
    }
}
