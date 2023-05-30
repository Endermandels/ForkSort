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
    int arr[] = {3, 0, 1, 42, 5};

    int err = sort(arr, 5);
    if (err) {
        return err;
    }

    return 0;
}
