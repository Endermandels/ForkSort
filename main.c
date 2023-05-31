/*
Fork Sort
Elijah Delavar
TODO: Files

TODO: Description
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergeSort.h"

int main(int argc, char const *argv[]) {
    int size = 1000000;
    int arr[size];

    for (int ii = 0; ii < size; ii++) {
        arr[ii] = ii;
    }

    clock_t t;
    t = clock();
    puts("Timer Start");

    // printf("Original Array: ");
    // printArray(arr, size);

    int err = process(arr, size);
    if (err) {
        return err;
    }
    
    // printf("Sorted Array:   ");
    // printArray(arr, size);

    t = clock() - t;
    double timeTaken = ((double)t)/CLOCKS_PER_SEC;
    printf("Timer Stop\nExecuted in %f seconds\n", timeTaken);

    return 0;
}
