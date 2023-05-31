/*
Fork Sort
Elijah Delavar
main.c mergeSort.c mergeSort.h Makefile

Perform merge sort on a given array using two processes and shared memory,
    only if the array has more than 10000 entries.
Otherwise, perform normal merge sort.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void printArray(int*,int,int);
int process(int*,int);

void printArray(int *arr, int start, int size) {
    for (int ii = start; ii < size; ii++) {
        printf("%d ", arr[ii]);
    }
    printf("\n");
}

// Credit: GeeksForGeeks
// https://www.geeksforgeeks.org/merge-sort/#
// This code was not modified
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Credit: GeeksForGeeks
// https://www.geeksforgeeks.org/merge-sort/#
// This code was not modified
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

/*
Split up the merge sort process if dealing with large arrays.
*/
int process(int *arr, int size) {
    if (size > 10000) {
        pid_t pid = fork();
        if (pid < 0) {
            puts("!!! Child Unsuccessfully Forked !!!");
            return 1;
        } else if (pid > 0) {
            mergeSort(arr, 0, (size/2)-1);

            while (wait(NULL) > 0);
            puts("Merging...");
        } else {
            mergeSort(arr, (size/2), size-1);

            puts("Exiting Child...");
            exit(EXIT_SUCCESS);
        }

        merge(arr, 0, (size/2)-1, size-1);
    } else {
        mergeSort(arr, 0, size-1);
    }
    return 0;
}