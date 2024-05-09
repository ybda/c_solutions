#ifndef CEXERCISES_MATH_H
#define CEXERCISES_MATH_H


#include <math.h>
#include <limits.h>
#include <stdint.h>

// 5! = 1 * 2 * 3 * 4 * 5 = 120
static unsigned long math_factorialRecursion(unsigned int n) {
    if (n <= 1) {
        return 1;
    }
    return n * math_factorialRecursion(n - 1);
}

static unsigned long math_factorialNoRecursion(unsigned int n) {
    unsigned long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

static unsigned long math_power(unsigned long n, unsigned int power) {
    if (power == 1) {
        return n;
    }

    if (power == 0) {
        return 1;
    }

    unsigned long res = n;
    for (int i = 1; i < power; i++) {
        res *= n;
    }
    return res;
}

static int32_t math_reverse(int x) {
    int32_t upperLimit = (pow(2, 31) - 1) / 10;
    int32_t lowerLimit = -(pow(2, 31) / 10);

    int32_t ans = 0;

    while (x) {
        int lastDigit = x % 10;

        if (ans <= upperLimit && ans >= lowerLimit) { // Checking if ans will be there in integer range only.
            ans = ans * 10 + lastDigit;
            x /= 10;
        } else { // ans would exceed the int if multiplied by 10. Thus integer overflow occur
            return 0;
        }

    }
    return ans;
}


#endif //CEXERCISES_MATH_H
