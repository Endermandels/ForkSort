/*
Fork Sort
Elijah Delavar
main.c mergeSort.c mergeSort.h Makefile

Compilation (gcc -Wall -std=gnu11 --pedantic):
    make        compile object files
    make run    run executable
    make runv   run executable in valgrind

Description:
    Perform merge sort using multi-processing and shared memory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <time.h>
#include "mergeSort.h"

int main(int argc, char const *argv[]) {
    int size = 1000000;
    // int arr[size];
    int *arr = (int*)mmap(NULL, sizeof(int)*size, PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);  // Shared Memory

    for (int ii = 0; ii < size; ii++) {
        arr[ii] = size - ii;
    }

    clock_t t;
    t = clock();
    puts("Timer Start");

    printf("Original Array: ");
    printArray(arr, 0, 8);

    int err = process(arr, size);
    if (err) {
        return err;
    }
    
    printf("Sorted Array (head):   ");
    printArray(arr, 0, 8);
    printf("Sorted Array (tail):   ");
    printArray(arr, size-8, size);

    t = clock() - t;
    double timeTaken = ((double)t)/CLOCKS_PER_SEC;
    printf("Timer Stop\nExecuted in %f seconds\n", timeTaken);

    return 0;
}
