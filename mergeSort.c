/*
Fork Sort
Elijah Delavar
TODO: Files

TODO: Description
*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int*,int);
int sort(int*,int);

void printArray(int *arr, int size) {
    for (int ii = 0; ii < size; ii++) {
        printf("%d ", arr[ii]);
    }
    printf("\n");
}

int sort(int *arr, int size) {
    printf("Original Array: ");
    printArray(arr, size);



    printf("Sorted Array:   ");
    printArray(arr, size);
    return 0;
}