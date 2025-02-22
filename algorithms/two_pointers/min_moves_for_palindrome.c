#include<stdio.h>
#include<stdlib.h>

void swap(char *target, int i, int j)
{
    char temp = target[i];
    target[i] = target[j];
    target[j] = temp;
}

int min_moves(char *target)
{
    int moves = 0;
    int len = 0;
    while(target[len] != '\0') {
        len++;
    }
    int start = 0;
    int end = len - 1;
    while(start < end)
    {
        if(target[start] == target[end])
        {
            start++;
            end--;
        }
        else {
            int j = end;
            int i = start;
            while(target[start] != target[end] && start < end)
            {
                end--;
            }
            if(start == end)
            {
                // Move start into middle
                int mid = len / 2;
                while(start < mid)
                {
                    swap(target, start, start+1);
                    start++;
                    moves++;
                }
                start = i;
            }
            else {
                // Move end to jth position and continue
                while(end < j)
                {
                    swap(target, end, end+1);
                    end++;
                    moves++;
                }
                start = i+1;
                end--;
            }
        }
    }

    return moves;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./a.out <string: target>");
        exit(1);
    }

    char *target = argv[1];

    int moves = min_moves(target);
    printf("%d moves are required to make string palindrome.\n", moves);
    return 0;
}
