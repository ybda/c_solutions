#ifndef CEXERCISES_UTIL_H
#define CEXERCISES_UTIL_H


#include <stdio.h>

typedef void (*function_ptr)();

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
    printf("]");
}

static inline unsigned short util_hexCharToNum(char c) {
    return c > 64 ? c - 55 : c - 48;
}

static inline bool util_isDigit(char ch){
    return ch >= '0' && ch <= '9';
}


#endif //CEXERCISES_UTIL_H