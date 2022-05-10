/*
process is a state of the program
where it has been loaded onto the memory from 
binary file in hard disk
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();
    printf("Hello, Process!%d\n", pid);

    return 0;
}