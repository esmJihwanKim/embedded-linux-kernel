#include <stdio.h> 
#include <unistd.h>

/*
if we need to consider how processes will 
behave in this sort of situation, draw 
the memory layout first
*/ 

int value = 5; 

int main()
{
    fork();
    value += 5; 
    printf("Hello, fork()! %d\n", value);
    fork();
    value += 5; 
    printf("Hello, fork()! %d\n", value);
    fork();
    value += 5; 
    printf("Hello, fork()! %d\n", value); 
    
    return 0;
}