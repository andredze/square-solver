#ifndef SIMPLE_EXAMPLE_TESTS_H
#define SIMPLE_EXAMPLE_TESTS_H

#include <stdio.h>
#include <math.h>

const double EPS = 1e-8;
const int MAXLEN = 300;

typedef enum SolutionCount {
    ZERO_SOL,
    ONE_SOL,
    TWO_SOL,
    INF_SOL,
    ROOTSCOUNT_ERROR
} SolutionCount_t;

typedef struct Coeffs {
    double a;
    double b;
    double c;
} Coeffs_t;

typedef struct Roots {
    SolutionCount_t RootsCount;
    double x1;
    double x2;
} Roots_t;

typedef struct Equation {
    Coeffs_t coeffs;
    Roots_t roots;
} Equation_t;

#endif //SIMPLE_EXAMPLE_TESTS_H
