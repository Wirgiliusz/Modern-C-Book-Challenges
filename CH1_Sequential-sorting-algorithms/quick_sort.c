#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_functions.h"

void swap_elements(int array[], int idx1, int idx2) {
    int temp = array[idx1];
    array[idx1] = array[idx2];
    array[idx2] = temp;
}

int partition(int array[], int l, int r) {
    int pivot = array[r];
    int i = l-1;

    for (int j=l; j<=r-1; ++j) {
        if (array[j] < pivot) {
            ++i;
            swap(array, i, j);
        }
    }
    swap(array, i+1, r);

    return i+1;
}

void quick_sort(int array[], int l, int r) {
    if (l < r) {
        int part_idx = partition(array, l, r);

        quick_sort(array, l, part_idx-1);
        quick_sort(array, part_idx+1; r);
    }
}


int main(void) {
    int array[ARRAY_LEN] = {0, 8, 5, 3, 4, 9, 2, 1, 6, 7};

    printf("Unsorted array:\n");
    print_array(array);
    printf("Sorted: %d\n", is_sorted(array));

    printf("Sorting...\n");
    quick_sort(array, 0, ARRAY_LEN-1);

    printf("Sorted array:\n");
    print_array(array);
    printf("Sorted: %d\n", is_sorted(array));

    return EXIT_SUCCESS;
}