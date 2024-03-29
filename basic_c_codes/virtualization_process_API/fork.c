#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){

  printf("hello world (pid:%d)\n", (int)getpid());
  fflush(stdout);
  int rc = fork();
  if (rc < 0) {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0){
    // child (new process)
    printf("hello, I am child (pid:%d)\n", (int)getpid());
  }
  else{
    // parent goes down this path (main)
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
  }
  return 0;
  
}


/* fflush() is typically used for output stream only. Its purpose is to clear (or flush) the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream).  */
