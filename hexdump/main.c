#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hexdump.h"

void f() {
    char* allocated_st1 = malloc(100);
    char* allocated_st2 = malloc(100);

    // sprintf does not perform bounds checking, meaning it may write beyond the allocated memory if the string being written exceeds the available space. This can lead to undefined behavior or segmentation faults.
    // To avoid this, consider using snprintf instead, which allows you to specify a maximum number of characters to write, including the null terminator.
    sprintf(allocated_st1, "C programming is cool");
    sprintf(allocated_st2, "Strings are sequences of bytes");

    hexdump(allocated_st1, 100);
    hexdump(allocated_st2, 100);

    free(allocated_st1);
    free(allocated_st2);

    //char* allocated_again_st = malloc(100);
    //sprintf(allocated_again_st, "C programming is cool");
    //hexdump(allocated_again_st, 100);
}

int main() {
    f();
}
