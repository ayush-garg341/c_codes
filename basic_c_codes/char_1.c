#include <stdio.h>

int main()
{
    char ch = 291;
    printf("%d, %c\n", ch, ch);
    return 0;
}

// char is signed char by default unless otherwise specified and hence take values between -128 to + 127
// 291 is greater than 127 and hence goes to other side of the range and 35, # get printed.