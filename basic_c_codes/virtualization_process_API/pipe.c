#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void) {
  int pipefds[2];
  char buffer[5];
 
  if(pipe(pipefds) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }
 
  pid_t pid = fork();
 
  if(pid == 0) { // in child process
    printf("hello, I am child (pid:%d)\n", (int)getpid());
    char *pin = (char*)"4821"; // PIN to send
    close(pipefds[0]); // close read fd
    write(pipefds[1], pin, 5); // write PIN to pipe
    printf("Generating PIN in child and sending to parent...\n");
    sleep(2); // intentional delay
    exit(EXIT_SUCCESS);
  }
 
  if(pid > 0) { // in main process
    int rc = wait(NULL); // wait for child process to finish
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
    close(pipefds[1]); // close write fd
    read(pipefds[0], buffer, 5); // read PIN from pipe
    close(pipefds[0]); // close read fd
 
    printf("Parent received PIN '%s'\n", buffer);
  }
 
  return EXIT_SUCCESS;
}
