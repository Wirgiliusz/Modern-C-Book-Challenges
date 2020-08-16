#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_functions.h"

int main(void) {
    int array[ARRAY_LEN] = {0, 8, 5, 3, 4, 9, 2, 1, 6, 7};

    printf("Unsorted array:\n");
    print_array(array);
    printf("Sorted: %d\n", is_sorted(array));

    printf("Sorting...\n");
    merge_sort(array, 0, ARRAY_LEN-1);

    printf("Sorted array:\n");
    print_array(array);
    printf("Sorted: %d\n", is_sorted(array));

    return EXIT_SUCCESS;
}