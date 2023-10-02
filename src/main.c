#include <stdio.h>
#include "./math.h"
#include "./hexToDec.h"
#include "./romanNumParser.h"


void testFact() {
    printf("%lu", math_factorial(5));
}

void testFib() {
    printf(
            "[FIB WITHOUT CACHE] 1: %lu | 2: %lu | 3: %lu | 4: %lu | 5: %lu | 6: %lu",
            math_fibonacci(0) == 0, //1
            math_fibonacci(1) == 1, //2
            math_fibonacci(2) == 1, //3
            math_fibonacci(3) == 2, //4
            math_fibonacci(12) == 144, //5
            math_fibonacci(40) == 102334155 //6
    );
}

void testFibCache() {
    size_t cacheSz = 150;
    unsigned long cache[cacheSz];
    for (size_t i = 0; i < cacheSz; i++) {
        cache[i] = 0;
    }

    printf(
            "[FIB CACHE] 1: %lu | 2: %lu | 3: %lu | 4: %lu | 5: %lu | 6: %lu",
            math_fibonacciCache(0, cache) == 0, //1
            math_fibonacciCache(1, cache) == 1, //2
            math_fibonacciCache(2, cache) == 1, //3
            math_fibonacciCache(3, cache) == 2, //4
            math_fibonacciCache(12, cache) == 144, //5
            math_fibonacciCache(48, cache) == 4807526976 //6
    );
}

void testPower() {
    printf("%d", math_power(2, 3) == 8);
    printf("%d", math_power(100, 1) == 100);
    printf("%d", math_power(100, 0) == 1);
    printf("%d", math_power(2, 2) == 4);
    printf("%d", math_power(2, 4) == 16);
    printf("%d", math_power(3, 4) == 81);
}

void testHexToDec() {
    printf("%d", hexToDec("1A3") == 419);
    printf("%d", hexToDec("1234") == 4660);
    printf("%d", hexToDec("ABC0") == 43968);
    printf("%d", hexToDec("2A3F") == 10815);
    printf("%d", hexToDec("236E") == 9070);
    printf("%d", hexToDec("20F1") == 8433);
    printf("%d", hexToDec("29F1") == 10737);
}

void testRomanNumParser() {
    printf("%d", romanNumParser_parse("I") == 1);
    printf("%d", romanNumParser_parse("IV") == 4);
    printf("%d", romanNumParser_parse("V") == 5);
    printf("%d", romanNumParser_parse("VI") == 6);
    printf("%d", romanNumParser_parse("VII") == 7);
    printf("%d", romanNumParser_parse("VIV") == 9);
    printf("%d", romanNumParser_parse("XXXI") == 31);
    printf("%d", romanNumParser_parse("XXXVII") == 37);
    printf("%d", romanNumParser_parse("LXXI") == 71);
    printf("%d", romanNumParser_parse("LXXXIV") == 84);
    printf("%d", romanNumParser_parse("LXXXV") == 85);
    printf("%d", romanNumParser_parse("LXXXVI") == 86);
    printf("%d", romanNumParser_parse("XCIX") == 99);
    printf("%d", romanNumParser_parse("C") == 100);
    printf("%d", romanNumParser_parse("CCX") == 210);
    printf("%d", romanNumParser_parse("MMMCMXLI") == 3941);
}


int main() {
    testRomanNumParser();

    return 0;
}
