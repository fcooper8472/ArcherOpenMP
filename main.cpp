
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

    MandelbrotSet m;

    timer.PollTime();
    m.CalculateArea(4000u, 10u);
    std::cout << "Time elapsed: " << timer.GetElapsedTime() << " seconds" << std::endl;

}
