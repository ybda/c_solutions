#include "./romanNumParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./util.h"

static unsigned long romanNumParser_romanNumToNum(char n) {
    switch (n) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    perror("romanNumParser_romanNumToNum LETTER UNKNOWN");
    exit(1);
}

unsigned long romanNumParser_parse(const char* romanNum) {
    const size_t rnSz = util_strlen(romanNum);
    unsigned long* allNums = (unsigned long*)malloc(rnSz * sizeof(long));

    for (size_t i = 0; i < rnSz; i++) {
        allNums[i] = romanNumParser_romanNumToNum(romanNum[i]);
    }

    bool minus = false;
    unsigned long res = 0;
    for (size_t i = 0; i < rnSz; i++) {
        const size_t lastInd = rnSz - 1 - i;

        if (!minus) {
            res += allNums[lastInd];
        } else {
            res -= allNums[lastInd];
            minus = false;
        }

        if (lastInd - 1 >= 0 && allNums[lastInd] > allNums[lastInd-1]) {
            minus = true;
        }
    }

    free(allNums);

    return res;
}
