#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    fork();
    fork();
    fork();
    printf("Hello fork()!\n");
    return 0; 
}