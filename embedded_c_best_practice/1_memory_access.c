#define PA (*(volatile unsigned char *)0x30000000)

void init(void){
    PA |= (0x7 << 5); 
}