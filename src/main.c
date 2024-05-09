#include <stdio.h>
#include "./tests.h"


void testAll() {
    testFibobacciRecursion();
    putchar('\n');
    testFibonacciMemoization();
    putchar('\n');
    testFibonacciIterative();
    putchar('\n');
    testMathPower();
    putchar('\n');
    testHexToDec();
    putchar('\n');
    testMathFactorial();
    putchar('\n');
    testRomanNumParser();

    printf("\n\n\n");

    // multiline tests

    testQuicksort();
    putchar('\n');
    testBinarySearch();
}

int main() {
    testAll();

    return 0;
}
