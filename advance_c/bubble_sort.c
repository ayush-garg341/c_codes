#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void sort(long *array)
{
    int i = 0;
    bool sorted;

    do {
        sorted = true;
        for( i = 0; i < 31; i++ ) {
            long *item_one = &array[i];
            long *item_two = &array[i+1];
            long swap_store;

            if(*item_one <= *item_two)
            {
                continue;
            }
            sorted = false;

            swap_store = *item_two;
            *item_two = *item_one;
            *item_one = swap_store;
        }

    } while(!sorted );
}

int main() {
    long array[32];
    int i = 0;
    srand(time(NULL));


    // sizeof gives the total size of array in bytes, not the number of elements.
    // Since array has 32 elements and each element is 8 bytes ( long ), total size of array is 32*8 = 256 bytes
    // So rand() % sizeof array gives a random integer between 0 and 255, meaning loop can potentially try to access 256 elements.
    // Out of bound might happen as array can contain only 32 elements.
    for(i = 0; i < rand() % sizeof array; i++)
    {
        array[i] = rand();
    }
    sort(array);
    return 0;
}

// Run the program as while ./a.out ; do echo OK; done
// Check if core dump is enabled
// ulimit -c -> if 0 then disabled
// ulimit -c unlimited -> enable it
// core file is generated when there is a seg fault during program run
// gdb -c core
// print $pc -> program counter
// x $1 -> inspect memory at address
// bt -> backtrace
