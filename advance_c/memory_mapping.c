#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
    const char* filename = "example.txt";
    int fd = open(filename, O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }

    // Map the file to memory
    char *map = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(map == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    // Read content
    printf("File content: %.*s\n", (int)sb.st_size, map);

    // Modify content (e.g., change first byte)
    map[0] = 'H';

    // Unmap and close
    if (munmap(map, sb.st_size) == -1) {
        perror("munmap");
    }

    close(fd);
    return 0;
}

// echo "hello world" > example.txt
// compile with gcc
// ./a.out
