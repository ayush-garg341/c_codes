#include<stdio.h>
#include<stdlib.h>

int triplet_count = 0;

int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int** unique_triplets_k_sum(int arr[], int len, int target)
{
    int** triplet_arr = NULL;
    qsort(arr, len, sizeof(int), compare_ints);
    for(int i = 0; i < len - 2; i++)
    {

        // This is done to avoid duplicate elements at different indexes
        if(i != 0 && arr[i] == arr[i-1]) {
            continue;
        }

        // Starting from 0th index does not make sense as that tuple has already been processed when i = 0
        int start = i + 1;
        int end = len - 1;
        while(start < end)
        {
            if((arr[i] + arr[start] + arr[end]) == target)
            {
                triplet_count++;
                int* triplet = (int *)malloc(sizeof(int)*3);
                triplet[0] = arr[i];
                triplet[1] = arr[start];
                triplet[2] = arr[end];

                triplet_arr = (int **)realloc(triplet_arr, triplet_count * sizeof(int *));
                triplet_arr[triplet_count - 1] = triplet;

                start++;
                end--;

                // Avoiding duplicates
                while(start < end && arr[start] == arr[start-1]) {
                    start++;
                }

                // Avoiding duplicates
                while(start < end && arr[end] == arr[end+1]) {
                    end--;
                }
            }
            if((arr[i] + arr[start] + arr[end]) > target) {
                end--;
            }
            if((arr[i] + arr[start] + arr[end]) < target) {
                start++;
            }
        }
    }
    return triplet_arr;
}

int main(int argc, char *argv[])
{
    int arr[6] = {-2, 0, 2, -2, 1, -1};
    if(argc != 2)
    {
        printf("Usage: ./a.out <int: target>");
        exit(1);
    }
    char *str_target = argv[1];
    int target = atoi(str_target);
    int** triplets = unique_triplets_k_sum(arr, 6, target);
    for(int i = 0; i < triplet_count; i++)
    {
        int *triplet = triplets[i];
        printf("%d %d %d\n", triplet[0], triplet[1], triplet[2]);
    }

    return 0;

}
