#ifndef CEXERCISES_FIBONACCI_NUMBER_H
#define CEXERCISES_FIBONACCI_NUMBER_H

#include <stdint.h>

// 0: 0 | 1: 1 | 2: 1 | 3: 2 | 4: 3 | 5: 5 | 6: 8 | 7: 13 | 12: 144
// Time complexity: O(2^n) | Space complexity: O(2^n)
static unsigned long fibonacciNumber_recursion(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciNumber_recursion(n - 1) + fibonacciNumber_recursion(n - 2);
}

// #param cache = array filled with zeros with size n+1
// Time complexity: O(n) | Space complexity: O(n) + O(n)
static unsigned long fibonacciNumber_memoization(int n, unsigned long* cache) {
    if (n <= 1) {
        return n;
    }

    if (cache[n] != 0) {
        return cache[n];
    }

    return cache[n] = fibonacciNumber_memoization(n - 1, cache) +
                      fibonacciNumber_memoization(n - 2, cache);
}

// Time complexity: O(n) | Space complexity: O(1)
// Iterative Solution / Space Optimized Soln.
static unsigned long fibonacciNumber_iterativeSolution(int n) {
    if(n <= 1) {
        return n;
    }

    unsigned long prev2 = 0;
    unsigned long prev = 1;
    for(int i = 2; i <= n; i++) {
        unsigned long curr_i = prev2 + prev;
        prev2 = prev;
        prev = curr_i;
    }

    return prev;
}


#endif //CEXERCISES_FIBONACCI_NUMBER_H