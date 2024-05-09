#ifndef CEXERCISES_MATH_H
#define CEXERCISES_MATH_H


// 5! = 1 * 2 * 3 * 4 * 5 = 120
static unsigned long math_factorial(unsigned int n) {
    if (n <= 1) {
        return 1;
    }
    return n * math_factorial(n - 1);
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

#endif //CEXERCISES_MATH_H
