#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    #pragma omp parallel // compiler directive 
    {
        printf("I am a parallel region\n");
    }

    return 0; 
}