#include <iostream>
#include <omp.h>

int main()
{

#pragma omp parallel default(none)
{
    std::cout << omp_get_thread_num() << std::endl;
}

}
