#ifndef CEXERCISES_UTIL_H
#define CEXERCISES_UTIL_H


#include <stdio.h>

static inline size_t util_strlen(const char* s) {
    size_t i = 0;
    for (; s[i] != '\0'; i++) {
    }
    return i;
}

static void util_printIntArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


#endif //CEXERCISES_UTIL_H