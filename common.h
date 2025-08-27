#ifndef SIMPLE_EXAMPLE_TESTS_H
#define SIMPLE_EXAMPLE_TESTS_H

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const double EPS = 1e-8; // Possible inaccuracy for float numbers
const int MAXLEN = 300; // Maximum length of strings

//-----------------------------------
//! Enum object contains all possible
//! numbers of solutions
//-----------------------------------

typedef enum SolutionCount {
    ZERO_SOL,
    ONE_SOL,
    TWO_SOL,
    INF_SOL,
    ROOTSCOUNT_ERROR
} SolutionCount_t;

//-----------------------------------
//! Structure contains coefficients
//! of quadratic equation
//-----------------------------------

typedef struct Coeffs {
    double a;
    double b;
    double c;
} Coeffs_t;

//-----------------------------------
//! Structure contains roots for
//! quadratic equation and amount
//! of them
//-----------------------------------

typedef struct Roots {
    SolutionCount_t RootsCount;
    double x1;
    double x2;
} Roots_t;

//-----------------------------------
//! Structure contains structure with
//! coefficients and structure with
//! roots
//-----------------------------------

typedef struct Equation {
    Coeffs_t coeffs;
    Roots_t roots;
} Equation_t;

#endif //SIMPLE_EXAMPLE_TESTS_H
