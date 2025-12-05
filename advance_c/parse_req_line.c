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
    int i = 0;
    int file_name_len = 0;
    int space_count = 0;
    int first_space_index = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] != ' ')
        {
            printf("%c ", buffer[i]);
        }
        else
        {
            space_count++;
            if(space_count == 1) {
                file_name_len = i+1;
                first_space_index = i+1;
            }
            if(space_count == 2)
            {
                file_name_len = i - file_name_len;
                break;
            }
        }
        i++;
    }

    printf("first space %d and file name len %d\n", first_space_index, file_name_len);
    i = 0;
    char* file_name = malloc(sizeof(char) * (file_name_len + 1));
    while(buffer[first_space_index] != '\0')
    {
        if(buffer[first_space_index] == ' ')
        {
            break;
        }
        else {
            file_name[i] = buffer[first_space_index];
            i++;
        }
        first_space_index += 1;
    }
    file_name[file_name_len+1] = '\0';

    printf("file name: %s \n", file_name);

    return 0;
}
