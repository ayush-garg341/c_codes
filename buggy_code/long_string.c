#include<stdio.h>
#include<string.h>

int longer(char *s, char *t)
{
    // return strlen(s) - strlen(t) > 0;
    return strlen(s) > strlen(t);
}

int main() {
    char *a = "I am ayush";
    char *b = "I am garg";
    int res = longer(a, b);
    printf("%d\n", res);
    return 0;
}


// Prototype for library function strlen
// size_t strlen(const char *s)
// size_t is defined ( via typedef ) in header file stdio.h to be unsigned


// The case where length of s is smaller than length of t, strlen(s) - strlen(t) will yield negative ( signed number ) but casting will convert it into unsigned ( positive ) number and hence it will be greater than 0.


// Fix:
// return strlen(s) > strlen(t)
