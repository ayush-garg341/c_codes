#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <fcntl.h>
#include<sys/wait.h>
#include<errno.h>

#define BUFSIZE 4096

int main() {
    int pipefd[2];
    if(pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();

    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }

    if(pid == 0)
    {
        // Child process
        printf("Inside child\n");

        // FD numbers are copied, but file objects (file offset, access mode, open flags, lock state, Inode reference) are shared.
        // Writing from parent and child updates the same file offset.
        // The file descriptor table entries are duplicated -> it means closing in parent won't effect the child and vice-versa.
        close(pipefd[0]);

        // Redirect stdout to pipe write end
        if(dup2(pipefd[1], STDOUT_FILENO) == -1)
        {
            perror("dup2");
            exit(1);
        }

        // Close extra copy of write-end
        close(pipefd[1]);

        // Replace child process with "ls -l /usr/lib"
        execlp("ls", "ls", "-l", "/usr/lib", NULL);

        // If execlp fails
        perror("execlp");
        exit(1);
    }

    // -------------------------
    // PARENT PROCESS
    // -------------------------

    close(pipefd[1]);

    char buffer[BUFSIZE];
    ssize_t n;
    int file_count = 0;

    printf("Parent: reading directory listing from child...\n");

    // Read data from pipe until EOF ( EOF (child closed the pipe) )
    while((n = read(pipefd[0], buffer, BUFSIZE-1)) > 0)
    {
        buffer[n] = '\0';
        // printf("%s", buffer);

        // Basic analysis: count normal files (lines starting with '-')
        char* line = strtok(buffer, "\n");
        while(line != NULL)
        {
            if(line[0] == '-')
            {
                file_count += 1;
            }
            line = strtok(NULL, "\n");
        }
    }

    close(pipefd[0]);

    // Wait for child to finish, prevents parent from finishing early.
    int status;
    waitpid(pid, &status, 0);

    printf("\nParent summary: Found %d regular files in /usr/lib\n", file_count);
    return 0;
}

// After fork(), parent and child become two completely separate processes and they run independently, concurrently, and in parallel (depending on CPU cores).
// After fork, the memory is duplicated with Copy-on-Write. They run independently in separate address spaces.
// COW: Parent and child share the same physical memory pages. They are marked as read-only and shared. Neither process knows they are shared—the OS manages it.
// So when is the memory actually copied? Not at fork time. The copy happens only if and when: Either parent or child tries to write to a shared page.
// On exec -> Child replaces all memory -> COW discarded. exec() throws away the entire address space of the calling process (the child) and loads a completely new program. None of the old pages are kept. They are replaced with new code (.text), new data (.data, .bss), new stack, new heap, new shared libraries, new environment, new argv. This is a complete memory replacement. Since the child discards ALL the shared pages, the OS NEVER needs to copy anything.

// dup -> int newfd = dup(oldfd);
// Kernel finds the lowest-numbered unused FD
// Returns it
// Both FDs refer to the same open file description (same file offset, same flags)
// Creates a separate FD table entry.


// dup2 -> dup2(oldfd, newfd);
// If oldfd == newfd: Returns newfd, no-op.
// If newfd is already open: Kernel closes it automatically.
// Kernel makes newfd a duplicate of oldfd.
// dup2(pipefd[1], 1); -> Make STDOUT (fd=1) point to the pipe’s write end.


// Why doing n = read(pipefd[0], buffer, BUFSIZE-1) inside of while loop, not just once and then checking if n > 0??
// read returns up to the number of bytes you ask for, could return less, could return more later, could return exactly 0 when EOF.
// Pipes deliver data in chunks - not all at once.
// It flushes output in unpredictable chunks, Kernel pipe buffer is 64 KB, Output arrives as the program runs, not all at once, Parent may read before child finishes writing.
// One read() = one chunk, Multiple read() calls = full output
// This while loop is universal for Linux/Unix: reading from pipes, reading from sockets, reading from terminals, reading from files, reading from network streams, reading from FIFOs, reading from character devices.
// read() on a PIPE never returns 0 just because “there is no data right now.” It returns 0 only when: ALL writers to the pipe have closed their write-ends. That is what makes it true EOF, not “temporary emptiness.”
// If the pipe is empty but writers are still alive → read() BLOCKS, not return 0.
