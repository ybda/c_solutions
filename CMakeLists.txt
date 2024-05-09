cmake_minimum_required(VERSION 3.26)
project(cexercises C)

set(CMAKE_C_STANDARD 23)

add_executable(${PROJECT_NAME}
        src/binarySearch.h
        src/fibonacciNumber.h
        src/hexDec.h
        src/main.c
        src/math.h
        src/quicksort.h
        src/romanNumParser.c
        src/romanNumParser.h
        src/util.h
)
