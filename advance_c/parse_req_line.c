#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    char buffer[] = "GET /tmp/tmpzm6bw_1z HTTP/1.1\r\nHost: localhost\r\nUser-Agent: python-requests/2.32.4\r\nAccept-Encoding: gzip, deflate, zstd\r\nAccept: */*\r\nConnection: keep-alive\r\n\r\n";

    // const char delimeter[] = " ";
    //
    // char *token;
    //
    // token = strtok(buffer, delimeter);
    //
    // while(token != NULL)
    // {
    //     printf("Token: %s\n", token);
    //     token = strtok(NULL, delimeter);
    // }

    char *filename = malloc(sizeof(char()) * 256);
    int rsi = 0; // will represent rsi register for finding first space index
    int rcx = 0; // index used for copying into filename

    while(buffer[rsi] != ' ')
    {
        rsi++;
    }

    rsi++; // next char to first space
    while(buffer[rsi] != ' ')
    {
        filename[rcx] = buffer[rsi];
        rsi++;
        rcx++;
    }

    filename[rcx] = '\0'; // null terminating the string

    printf("Filename: %s\n", filename);

    return 0;
}
