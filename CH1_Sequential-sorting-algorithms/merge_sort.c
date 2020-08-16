#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_LEN 10

void merge(int array[], int l, int m, int r) {
    int L_len = m - l + 1;
    int R_len = r - m;
    int array_L[L_len];
    int array_R[R_len];
    for (int i = 0; i < L_len; ++i) {
        array_L[i] = array[l+i];
    }
    for (int i = 0; i < R_len; ++i) {
        array_R[i] = array[m+1+i];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < L_len && j < R_len) {
        if (array_L[i] <= array_R[j]) {
            array[k] = array_L[i];
            ++i;
        } else {
            array[k] = array_R[j];
            ++j;
        }
        ++k;
    }

    while (i < L_len) {
        array[k] = array_L[i];
        ++i;
        ++k;
    }

    while (j < R_len) {
        array[k] = array_R[j];
        ++j;
        ++k;
    }
}

void merge_sort(int array[], int l, int r) {
    if (r > l) {
        int m = (l+r)/2;
        merge_sort(array, l, m);
        merge_sort(array, m+1, r);

        merge(array, l, m, r);
    }
}

void print_array(int array[]) {
    for (int i=0; i<ARRAY_LEN; ++i) {
        i==(ARRAY_LEN-1) ? printf("%d\n", array[i]) : printf("%d ", array[i]);
    }
}

bool is_sorted(int array[]) {
    for (int i=0; i<ARRAY_LEN-1; ++i) {
        if(array[i] > array[i+1]) {
            return false;
        }
    }

    return true;
}

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