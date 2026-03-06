#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: exec-suid program args...\n");
        return 1;
    }

    char **cmd = &argv[1];

    /* Execute the requested program */
    execvp(cmd[0], cmd);

    perror("execvp failed");
    return 1;
}
