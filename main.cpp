#include <iostream>
#include <omp.h>

int main()
{

    int sum = 0;

#pragma omp parallel default(none) reduction(+:sum)
{
    sum = omp_get_thread_num();
}

    std::cout << sum << std::endl;

}
