#include <stdlib.h>
#include "./hexToDec.h"
#include "./strutil.h"
#include "./math.h"

static inline unsigned short hexCharToNum(char c) {
    return c > 64 ? c - 55 : c - 48;
}

unsigned long hexToDec(const char* hex) {
    size_t len = strutil_strlen(hex);
    unsigned short* nums = (unsigned short*) malloc(len * sizeof(unsigned short));

    for (size_t i = 0; i < len; i++) {
        nums[i] = hexCharToNum(hex[i]);
    }

    for (size_t i = 0; i < len; i++) {
        nums[len - 1 - i] = nums[len - 1 - i] * math_power(16, i);
    }

    unsigned long res = 0;
    for (size_t i = 0; i < len; i++) {
        res += nums[i];
    }

    free(nums);
    return res;
}
