#include<stdio.h>
#include<stdlib.h>

typedef int (*perform_func)(char* type, char* name);

int perform_read(char* type, char* name)
{
    printf("Type is: %s\n", type);
    printf("Name is: %s\n", name);
    // some other read specific logic
    return 0;
}

int perform_write(char* type, char* name)
{
    printf("Type is: %s\n", type);
    printf("Name is: %s\n", name);
    // some other write specific logic
    return 0;
}

int perform_seek(char* type, char* name)
{
    printf("Type is: %s\n", type);
    printf("Name is: %s\n", name);
    // some other seek specific logic
    return 0;
}

int perform_close(char* type, char* name)
{
    printf("Type is: %s\n", type);
    printf("Name is: %s\n", name);
    // some other close specific logic
    return 0;
}

struct fun_args {

    char type[50];
    char name[50];
    perform_func fun_name;
};

struct fun_args args_arr[4] = {
    {"read", "perform read", perform_read},
    {"write", "perform write", perform_write},
    {"seek", "perform seek", perform_seek},
    {"close", "perform close", perform_close},

};

int main()
{
    perform_func operations[4] = {NULL, NULL, NULL, NULL};
    operations[0] = perform_read;
    operations[1] = perform_write;
    operations[2] = perform_seek;
    operations[3] = perform_close;

    for(int i = 0; i <= 3; i++)
    {
        //operations[i](args_arr[i].type, args_arr[i].name);
        args_arr[i].fun_name(args_arr[i].type, args_arr[i].name);
    }
    return 0;
}

// A function pointer lets you store a function in a variable, pass it as an argument, or return it from another function.
// C has no classes, but function pointers allow you to "attach" behavior to objects.
