#include <stdio.h>

int main()
{
    char ch;
    for (ch = 0; ch <= 255; ch++)
    {
        printf("%d %c\n", ch, ch);
    }

    return 0;
}

// this will turn into infinite loop since after 127 the ch++ will go to other side of the range and will always be less
// than 255