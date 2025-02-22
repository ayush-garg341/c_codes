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
            while(target[start] != target[j] && start < j)
            {
                j--;
            }
            if(start == j)
            {
                // Move start into middle
                // Not actually moving the middle character, just calculating the num of moves
                moves += len / 2 - start;
                start++;
            }
            else {
                // Move end to jth position and continue
                while(j < end)
                {
                    swap(target, j, j+1);
                    j++;
                    moves++;
                }
                start++;
                end--;
            }
        }
    }
    printf("%s\n", target);
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
