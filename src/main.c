#include <stdio.h>
#include "./tests.h"

// Define a function type

void testAll() {
    function_ptr functions[] = {
            tests_fibonacci,
            tests_mathPower,
            tests_mathAtoi,
            tests_mathIsPalindrome,
            tests_hexDec,
            tests_mathFactorial,
            tests_romanNumParser,
            tests_mathReverse,
            tests_quicksort,
            tests_binarySearch
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
