#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 10

int main(void) {
    int array[ARRAY_LEN] = {0, 8, 5, 3, 4, 9, 2, 1, 6};

    printf("Unsorted array:\n");
    for (int i=0; i<ARRAY_LEN; ++i) {
        i==(ARRAY_LEN-1) ? printf("%d\n", array[i]) : printf("%d ", array[i]);
    }

    return EXIT_SUCCESS;
}