#define TEMP (*(volatile unsigned int *)0x001)

void main(void){
    int a[10], i;
    volatile int j; 

    TEMP = 0x0;
    for(i = 0; i < 10; i++){
        a[i] = TEMP;
        for(j = 0; j < 100000; j++); 
    }

    for(i = 0; i < 10; i++)
        print("a[%d] = %d \t", i, a[i]); 
}