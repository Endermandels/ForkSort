/*
Fork Sort
Elijah Delavar
TODO: Files

TODO: Description
*/

#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"

int main(int argc, char const *argv[]) {
    int arr[] = {3};
    int size = 1;

    printf("Original Array: ");
    printArray(arr, size);

    int err = sort(arr, size);
    if (err) {
        return err;
    }
    
    printf("Sorted Array:   ");
    printArray(arr, size);

    return 0;
}
