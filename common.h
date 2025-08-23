#ifndef SIMPLE_EXAMPLE_TESTS_H
#define SIMPLE_EXAMPLE_TESTS_H

#include <stdio.h>
#include <math.h>

const double EPS = 1e-8;

typedef enum SolutionCount {
    ZERO_SOL,
    ONE_SOL,
    TWO_SOL,
    INF_SOL,
    ROOTSCOUNT_ERROR
} SolutionCount_t;

typedef struct Equation {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    SolutionCount_t RootsCount;
} Equation_t;

#endif //SIMPLE_EXAMPLE_TESTS_H
