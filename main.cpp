#include <iostream>
#include <omp.h>
#include <sstream>

#include "MandelbrotSet.hpp"

int main()
{

    int sum = 0;

#pragma omp parallel default(none) shared(std::cout) reduction(+:sum)
{
    sum = omp_get_thread_num();

    std::stringstream s;
    s << omp_get_thread_num() << std::endl;

    std::cout << s.str();
}

    std::cout << sum << std::endl;

    MandelbrotSet m;
    m.CalculateArea(2000u, 200u);
}
