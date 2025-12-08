#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }
    if(pid == 0)
    {
        // Inside child
        printf("Inside child process\n");
        exit(0); // important to have, if not then it will execute the second printf or the parent process code should be in else statement.
    }

    int status;
    waitpid(pid, &status, 0);

    printf("Inside parent process\n");
    return 0;
}
