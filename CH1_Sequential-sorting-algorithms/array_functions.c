#include <stdbool.h>
#include "array_functions.h"


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