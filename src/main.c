#include <stdio.h>
#include "./tests.h"

// Define a function type

void testAll() {
    function_ptr functions[] = {
            testFibobacciRecursion,
            testFibonacciMemoization,
            testMathPower,
            testHexToDec,
            testDecToHex,
            testMathFactorial,
            testRomanNumParser,
            testMathReverse,
            testQuicksort,
            testBinarySearch
    };

    for (int i = 0; i < (sizeof(functions) / sizeof(functions[0])); i++) {
        functions[i]();
        putchar('\n');
    }
}

int main() {
    testAll();

    return 0;
}
