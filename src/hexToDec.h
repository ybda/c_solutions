#ifndef CEXERCISES_HEXTODEC_H
#define CEXERCISES_HEXTODEC_H


#include <stdlib.h>
#include "./hexToDec.h"
#include "./util.h"
#include "./math.h"

static unsigned long hexToDec(const char* hex) {
    unsigned long res = 0;
    unsigned long multiplier = 1;

    for (size_t i = util_strlen(hex) - 1; i < util_strlen(hex); i--) {
        unsigned short num = util_hexCharToNum(hex[i]);
        res += num * multiplier;
        multiplier *= 16;
    }

    return res;
}


#endif //CEXERCISES_HEXTODEC_H
