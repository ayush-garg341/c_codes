// crash.c
#include <stdio.h>

int main() {
    int *ptr = NULL;
    *ptr = 42;  // Segmentation fault
    return 0;
}


// gcc -g crash.c -o crash
// ./crash
// If core dumps are enabled, a core.* file will be generated.
// gdb ./crash core
