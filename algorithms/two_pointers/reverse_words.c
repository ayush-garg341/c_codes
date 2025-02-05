#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* reverse_words(char *str, int len)
{

    // Using len+1 as we have to accomodate null \0 char as well.
    char *allocated_str = malloc(len+1);
    strcpy(allocated_str, str);
    char temp;
    int start = 0;
    int end = len - 1;
    while(start<end)
    {
        temp = allocated_str[start];
        allocated_str[start] = allocated_str[end];
        allocated_str[end] = temp;
        start++;
        end--;
    }

    start = 0;
    int begin = 0;
    end = 0;
    char* reversed_str = malloc(len+1);
    int reversed_idx = 0;
    while(allocated_str[start] != '\0')
    {
        if(allocated_str[start] == ' ')
        {
            // Trimming whitespaces
            start++;
        }
        else {
            begin = start;
            while(allocated_str[start]!=' ' && allocated_str[start] != '\0')
            {
                // Checking the number of non-whitespace characters
                end = start;
                start++;
            }

            while(end>=begin)
            {
                // Reading the chars backwards and assigning to reversed_str
                reversed_str[reversed_idx] = allocated_str[end];
                reversed_idx++;
                end--;
            }

            if(allocated_str[start] != '\0') {
                // Adding a single space after each word. But making sure it's not end of sentence.
                reversed_str[reversed_idx] = ' ';
                reversed_idx++;
            }
        }
    }

    // Making sure string ends up properly with NULL character.
    reversed_str[reversed_idx] = '\0';

    free(allocated_str);
    return reversed_str;
}

int main(int argc, char *argv[])
{
    // char *str = "I have 3 cats and 1 dog";
    char *str = "   MULtiple   Spaces      ";
    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    printf("%s %d\n", str, len);
    char* reversed_str = reverse_words(str, len);
    printf("%s\n", reversed_str);
    free(reversed_str);
}
