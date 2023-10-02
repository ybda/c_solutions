#ifndef CEXERCISES_MATH_H
#define CEXERCISES_MATH_H


// 5! = 1 * 2 * 3 * 4 * 5 = 120
static unsigned long math_factorial(unsigned int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * math_factorial(n - 1);
}


// 0: 0 | 1: 1 | 2: 1 | 3: 2 | 4: 3 | 5: 5 | 6: 8 | 7: 13 | 12: 144
static unsigned long math_fibonacci(unsigned int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return math_fibonacci(n - 1) + math_fibonacci(n - 2);
}

// #param cache = array filled with zeros
static unsigned long math_fibonacciCache(unsigned int n, unsigned long* cache) {
    if (n == 0 || n == 1) {
        return n;
    }

    unsigned long cacheNum = cache[n];
    if (cacheNum != 0) {
        return cacheNum;
    } else {
        unsigned long result = math_fibonacciCache(n - 1, cache) + math_fibonacciCache(n - 2, cache);
        cache[n] = result;
        return result;
    }
}


static unsigned long math_power(unsigned long n, unsigned int power) {
    if (power == 1) {
        return n;
    } else if (power == 0) {
        return 1;
    }
    unsigned long res = n;
    for (int i = 1; i < power; i++) {
        res *= n;
    }
    return res;
}

#endif //CEXERCISES_MATH_H
