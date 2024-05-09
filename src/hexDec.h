#ifndef CEXERCISES_HEXDEC_H
#define CEXERCISES_HEXDEC_H


#include <stdlib.h>
#include "./util.h"
#include "./math.h"

static unsigned long hexDec_toDec(const char* hex) {
    unsigned long res = 0;
    unsigned long multiplier = 1;

    for (size_t i = util_strlen(hex) - 1; i < util_strlen(hex); i--) {
        unsigned short num = util_hexCharToNum(hex[i]);
        res += num * multiplier;
        multiplier *= 16;
    }

    return res;
}

static char* hexDec_toHex(const int num) {
    if (num == 0) {
        char* hex = (char*)malloc(2 * sizeof(char));
        hex[0] = '0';
        hex[1] = '\0';
        return hex;
    }
    unsigned int num1 = num; // takes care of negative integers automatically
    int len = 0;
    while (num1 > 0) {
        num1 = num1 / 16;
        len++;
    }
    char* const hex = (char*)malloc((len + 1) * sizeof(char));
    hex[len] = '\0';
    num1 = num;
    for (int i = len - 1; i >= 0; i--) {
        int rem = num1 % 16;
        if (rem < 10) {
            hex[i] = '0' + rem;
        } else {
            hex[i] = 'A' + (rem - 10);
        }
        num1 = num1 / 16;
    }
    return hex;
}


#endif //CEXERCISES_HEXDEC_H
