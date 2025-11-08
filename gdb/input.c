#include<stdio.h>
#include<stdlib.h>

void my_hello_function(char **names, int count)
{
    for(int i = 0; i < count; i++)
    {
        printf("hello %s\n", names[i]);
    }
}

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        puts("argc is less than 2");
        exit(1);
    }
    my_hello_function(argv, argc);
    return 0;
}

