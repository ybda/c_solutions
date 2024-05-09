#ifndef CEXERCISES_TESTS_H
#define CEXERCISES_TESTS_H


#include <string.h>
#include "./math.h"
#include "./hexDec.h"
#include "./romanNumParser.h"
#include "./util.h"
#include "./quicksort.h"
#include "./binarySearch.h"
#include "./fibonacciNumber.h"

void testMathFactorial() {
    printf("[math_factorialRecursion & math_factorialNoRecursion] ");

    struct {
        int input;
        long expected;
    } testCases[] = {
            {0,  1},
            {1,  1},
            {2,  2},
            {3,  6},
            {4,  24},
            {5,  120},
            {6,  720},
            {7,  5040},
            {8,  40320},
            {9,  362880},
            {10, 3628800},
            {11, 39916800},
            {12, 479001600},
            {13, 6227020800},
            {14, 87178291200},
            {15, 1307674368000},
    };

    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", math_factorialRecursion(testCases[i].input) == testCases[i].expected);
        printf("%d", math_factorialNoRecursion(testCases[i].input) == testCases[i].expected);
    }
}

void testMathAtoi() {
    printf("[math_atoi] ");

    struct {
        const char *input;
        int expected;
    } testCases[] = {
            {"  325  ",  325},
            {"42",  42},
            {"-042",  -42},
            {"1337c0d3",  1337},
            {"0-1",  0},
            {"words and 987",  0}
    };

    for (size_t i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", math_atoi(testCases[i].input) == testCases[i].expected);
    }
}

void testFibonacci() {
    printf("[fibonacciNumber_memoization & fibonacciNumber_iterativeSolution & fibonacciNumber_recursion] ");

    size_t cacheSz = 150;
    unsigned long cache[cacheSz];
    for (size_t i = 0; i < cacheSz; i++) {
        cache[i] = 0;
    }

    struct {
        int input;
        unsigned long expected;
    } testCases[] = {
            {0,  0},
            {1,  1},
            {2,  1},
            {3,  2},
            {12, 144},
            {40, 102334155},
            {61, 2504730781961}
    };

    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", fibonacciNumber_memoization(testCases[i].input, cache) == testCases[i].expected);
        printf("%d", fibonacciNumber_iterativeSolution(testCases[i].input) == testCases[i].expected);

        // Condition is required to not wait forever
        if (testCases[i].input < 41) {
            printf("%d", fibonacciNumber_recursion(testCases[i].input) == testCases[i].expected);
        }

        putchar(' ');
    }
}

void testMathPower() {
    printf("[math_power] ");

    struct {
        int base;
        int exponent;
        int expected;
    } testCases[] = {
            {2,   3, 8},
            {100, 1, 100},
            {100, 0, 1},
            {2,   2, 4},
            {2,   4, 16},
            {3,   4, 81}
    };

    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", math_power(testCases[i].base, testCases[i].exponent) == testCases[i].expected);
    }
}

void testHexDec() {
    printf("[hexDec_toDec & hexDec_toHex] ");

    struct {
        const char *input;
        int expected;
    } testCases[] = {
            {"1A3",  419},
            {"1234", 4660},
            {"ABC0", 43968},
            {"2A3F", 10815},
            {"236E", 9070},
            {"20F1", 8433},
            {"29F1", 10737},
    };

    for (size_t i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", hexDec_toDec(testCases[i].input) == testCases[i].expected);

        char *s = hexDec_toHex(testCases[i].expected);
        printf("%d", strcmp(s, testCases[i].input) == 0);
        free(s);
    }
}

void testRomanNumParser() {
    printf("[romanNumParser_parse] ");

    struct {
        const char *input;
        int expected;
    } testCases[] = {
            {"I",        1},
            {"III",      3},
            {"IV",       4},
            {"V",        5},
            {"VI",       6},
            {"VII",      7},
            {"VIV",      9},
            {"XXXI",     31},
            {"XXXVII",   37},
            {"LXXI",     71},
            {"LXXXIV",   84},
            {"LXXXV",    85},
            {"LXXXVI",   86},
            {"XCIX",     99},
            {"C",        100},
            {"CCX",      210},
            {"MMMCMXLI", 3941}
    };

    for (size_t i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", romanNumParser_parse(testCases[i].input) == testCases[i].expected);
    }
}

void testMathReverse() {
    printf("[math_reverse] ");

    struct {
        int input;
        int expected;
    } testCases[] = {
            {1234,     4321},
            {-123,     -321},
            {120,      21},
            {123456,   654321},
            {789012,   210987},
            {890123,   321098},
            {901234,   432109},
            {1234567,  7654321},
            {2345678,  8765432},
            {3456789,  9876543},
            {4567890,  987654},
            {5678901,  1098765},
            {6789012,  2109876},
            {-7890123,  -3210987},
            {8901234,  4321098},
            {9012345,  5432109},
            {12345678, 87654321},
            {23456789, 98765432},
            {34567890, 9876543},
            {45678901, 10987654},
            {56789012, 21098765},
            {67890123, 32109876},
            {78901234, 43210987},
            {89012345, 54321098},
            {901234536, 635432109},
            {-901234536, -635432109}
    };

    for (size_t i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", math_reverse(testCases[i].input) == testCases[i].expected);
    }
}

void testQuicksort() {
    printf("--[Quicksort]--\n");

    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    util_printIntArray(arr, size);
    putchar('\n');

    quicksort(arr, 0, size - 1);

    printf("Sorted array: ");
    util_printIntArray(arr, size);
}

void testBinarySearch() {
    printf("--[BinarySearch]--\n");

    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = 8;

    printf("Original array: ");
    util_printIntArray(arr, size);
    putchar('\n');

    // Perform binary search
    int index = binarySearch(arr, 0, size - 1, num);

    if (index != -1)
        printf("%d found at index %d.", num, index);
    else
        printf("%d not found in the array.", num);
}


#endif //CEXERCISES_TESTS_H
