#include<stdio.h>

int main() {
    int a = 2147483647; // Max value for 32-bit int
    int b = a + 1;      // Overflow: undefined behavior
    printf("%d\n", b);  // Will print a negative number on the other side
}
