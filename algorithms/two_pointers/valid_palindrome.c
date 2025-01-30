#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int is_palindrome(char *str)
{
    int len = strlen(str);
    int fwd = 0;
    int bkwd = len - 1;
    while(fwd <= bkwd)
    {
        if(str[fwd] == str[bkwd]) {
            fwd++;
            bkwd--;
        }
        else {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./a.out <str>");
        exit(1);
    }
    char *str = argv[1];
    int palindrome = is_palindrome(str);
    printf("%s\n", palindrome==1?"String is palindrome": "String not a palindrome");
    return 0;
}
