#ifndef CEXERCISES_TESTS_H
#define CEXERCISES_TESTS_H


#include "./math.h"
#include "./hexToDec.h"
#include "./romanNumParser.h"
#include "./util.h"
#include "./quicksort.h"
#include "./binarySearch.h"
#include "./fibonacciNumber.h"

void testMathFactorial() {
    struct {
        int input;
        long expected;
    } testCases[] = {
            {0, 1},
            {1, 1},
            {2, 2},
            {3, 6},
            {4, 24},
            {5, 120},
            {6, 720},
            {7, 5040},
            {8, 40320},
            {9, 362880},
            {10, 3628800},
            {11, 39916800},
            {12, 479001600},
            {13, 6227020800},
            {14, 87178291200},
            {15, 1307674368000},
    };

    printf("[math_factorial] ");
    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", math_factorial(testCases[i].input) == testCases[i].expected);
    }
}

void testFibobacciRecursion() {
    struct {
        int input;
        unsigned long expected;
    } testCases[] = {
            {0, 0},
            {1, 1},
            {2, 1},
            {3, 2},
            {12, 144},
            {40, 102334155}
    };

    printf("[fibonacciNumber_recursion] ");
    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", fibonacciNumber_recursion(testCases[i].input) == testCases[i].expected);
    }
}

void testFibonacciMemoization() {
    size_t cacheSz = 150;
    unsigned long cache[cacheSz];
    for (size_t i = 0; i < cacheSz; i++) {
        cache[i] = 0;
    }

    struct {
        int input;
        unsigned long expected;
    } testCases[] = {
            {0, 0},
            {1, 1},
            {2, 1},
            {3, 2},
            {12, 144},
            {40, 102334155},
            {61, 2504730781961}
    };

    printf("[fibonacciNumber_memoization] ");
    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", fibonacciNumber_memoization(testCases[i].input, cache) == testCases[i].expected);
    }
}

void testFibonacciIterative() {
    struct {
        int input;
        unsigned long expected;
    } testCases[] = {
            {0, 0},
            {1, 1},
            {2, 1},
            {3, 2},
            {12, 144},
            {40, 102334155},
            {61, 2504730781961}
    };

    printf("[fibonacciNumber_iterativeSolution] ");
    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", fibonacciNumber_iterativeSolution(testCases[i].input) == testCases[i].expected);
    }
}

void testMathPower() {
    struct {
        int base;
        int exponent;
        int expected;
    } testCases[] = {
            {2, 3, 8},
            {100, 1, 100},
            {100, 0, 1},
            {2, 2, 4},
            {2, 4, 16},
            {3, 4, 81}
    };

    printf("[math_power] ");
    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", math_power(testCases[i].base, testCases[i].exponent) == testCases[i].expected);
    }
}

void testHexToDec() {
    printf("[hexToDec] ");

    struct {
        const char* input;
        int expected;
    } testCases[] = {
            {"1A3", 419},
            {"1234", 4660},
            {"ABC0", 43968},
            {"2A3F", 10815},
            {"236E", 9070},
            {"20F1", 8433},
            {"29F1", 10737},
    };

    for (size_t i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", hexToDec(testCases[i].input) == testCases[i].expected);
    }
}

void testRomanNumParser() {
    printf("[romanNumParser_parse] ");

    struct {
        const char* input;
        int expected;
    } testCases[] = {
            {"I", 1},
            {"III", 3},
            {"IV", 4},
            {"V", 5},
            {"VI", 6},
            {"VII", 7},
            {"VIV", 9},
            {"XXXI", 31},
            {"XXXVII", 37},
            {"LXXI", 71},
            {"LXXXIV", 84},
            {"LXXXV", 85},
            {"LXXXVI", 86},
            {"XCIX", 99},
            {"C", 100},
            {"CCX", 210},
            {"MMMCMXLI", 3941}
    };

    for (size_t i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printf("%d", romanNumParser_parse(testCases[i].input) == testCases[i].expected);
    }
}

void testQuicksort() {
    printf("[Quicksort]\n");

    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    util_printIntArray(arr, size);

    quicksort(arr, 0, size - 1);

    printf("Sorted array: ");
    util_printIntArray(arr, size);
}

void testBinarySearch() {
    printf("[BinarySearch]\n");

    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = 8;

    printf("Original array: ");
    util_printIntArray(arr, size);

    // Perform binary search
    int index = binarySearch(arr, 0, size - 1, num);

    if (index != -1)
        printf("%d found at index %d.\n", num, index);
    else
        printf("%d not found in the array.\n", num);
}


#endif //CEXERCISES_TESTS_H
