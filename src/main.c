#include <stdio.h>
#include "./tests.h"

// Define a function type

void testAll() {
    function_ptr functions[] = {
            testFibobacciRecursion,
            testFibonacciMemoization,
            testFibonacciIterative,
            testMathPower,
            testHexToDec,
            testMathFactorial,
            testRomanNumParser,
            testQuicksort,
            testBinarySearch
    };

    for (int i = 0; i < (sizeof(functions) / sizeof(function_ptr)); i++) {
        functions[i]();
        putchar('\n');
    }
}

int main() {
    testAll();

    return 0;
}
