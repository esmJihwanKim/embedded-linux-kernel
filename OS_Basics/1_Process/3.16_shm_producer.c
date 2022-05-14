#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    const int SIZE = 4096; 
    const char *name = "OS";
    const char *message_0 = "Hello";
    const char *message_1 = "World!\n";

    int shm_fd;
    char *ptr; 
    //configure the size of the shared memory
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);
    // map the shared memory object 
    ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    
    sprintf(ptr, "%s", message_0);
    ptr += strlen(message_0);
    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_1);

    return 0; 
}

/*
gcc 3.16_shared_memory_shm.c -lrt 

flag used in this shell command is 
-l : link library
rt : real time 
librt is the realtime extensions library

this command will prompt the linker
to look for the librt.a or librt.so (shared object)

the realtime extensions library has functions like 
clock_gettime(), fork(), nanosleep() etc.. 
shm_open() is another one in this case
*/