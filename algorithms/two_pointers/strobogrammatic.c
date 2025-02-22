#include<stdio.h>
#include<stdlib.h>

int mapping_180[] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};

int check_strobogrammatic(char *target)
{
    int len = 0;
    while(target[len] != '\0')
    {
        len++;
    }
    int start = 0;
    int end = len - 1;
    while(start <= end)
    {
        int front_char = target[start] - '0';
        int end_char = target[end] - '0';
        if(front_char != mapping_180[end_char] && end_char != mapping_180[front_char]) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./a.out <int: target>");
        exit(1);
    }
    char *str_target = argv[1];

    int isstrobogrammatic = check_strobogrammatic(str_target);

    printf("%s\n", isstrobogrammatic == 1 ? "Is Strobogrammatic": "Not Strobogrammatic");

    return 0;
}
