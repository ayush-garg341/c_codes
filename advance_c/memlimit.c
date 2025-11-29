#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>

int main() {
    struct rlimit rl;

    // Set 200 MB soft and hard memory limit
    rl.rlim_cur = 200 * 1024 * 1024;   // soft limit
    rl.rlim_max = 200 * 1024 * 1024;   // hard limit

    if (setrlimit(RLIMIT_AS, &rl) != 0) {
        perror("setrlimit");
        return 1;
    }

    printf("Memory limit set to 200 MB.\n");
    printf("PID = %d\n", getpid());
    printf("Run: pmap %d\n", getpid());
    printf("Allocating memory...\n");

    size_t total = 0;
    size_t chunk = 10 * 1024 * 1024;  // allocate in 10 MB chunks

    while (1) {
        void *p = malloc(chunk);
        if (!p) {
            perror("malloc failed");
            printf("Total allocated before failure: %zu MB\n", total / (1024 * 1024));
            exit(1);
        }

        memset(p, 0, chunk);   // Touch the memory
        total += chunk;

        printf("Allocated total: %zu MB\n", total / (1024 * 1024));
        sleep(1); // slow down so we can inspect with pmap
    }

    return 0;
}

