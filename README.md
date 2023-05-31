# ForkSort

Elijah Delavar

## Description

Sorting large arrays using forked processes in order to become familiar with forking and shared memory.

Based on running the program multiple times,
    using regular merge sort half of the time
    and using multi-processing merge sort the other half of the time,
    the multi-processing merge sort reduced the runtime in half
    as compared with the single-process merge sort.

## Compilation

gcc -Wall -std=gnu11 --pedantic -o forksort main.o mergeSort.o

OR

make
