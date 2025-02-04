#include<stdio.h>
#include<stdlib.h>

void sort_colors(int arr[], int len)
{
    int temp;
    int left = 0;
    int right = len-1;
    int i = 0;
    while(i <= right)
    {
        if(arr[i] == 0)
        {
            temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            if(left == i) {
                i++;
                left++;
            }
            else {
                left++;
            }
        }
        else if(arr[i] == 2) {

            temp = arr[i];
            arr[i] = arr[right];
            arr[right] = temp;
            right--;

        }
        else {
            i++;
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {0, 1, 1, 2, 0, 2, 0, 2, 1, 2};
    sort_colors(arr, 10);
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
