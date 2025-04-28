#include<stdio.h>

int main()
{
    unsigned int a = 4294967295; // Max value for 32-bit unsigned int
    unsigned int b = a + 1;      // Wraps around to 0
    printf("%u\n", b);           // Print 0
}
