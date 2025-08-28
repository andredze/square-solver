//! @file

#ifndef TEST_H
#define TEST_H

#include "../common.h"
#include "../solve/solve.h"

//---------------------------------------------------------------
//! Tests solve_equation() by inputting different structures with
//! coefficients and expected results and comparing them with
//! given answers. Prints number of passed tests
//!
//! @param None
//!
//! @return 0 if test data was fine
//---------------------------------------------------------------

int test_solve_equation ();

//---------------------------------------------------------------
//! Tests solve_equation with one example of equation
//!
//! @param  expected  Pointer to a Equation_t, containing
//!                   a, b, c -coefficients, referenced roots x1, x2
//!                   and referenced number of roots;
//!
//! @return 1 in case of a mistake; 0 if everything is fine
//---------------------------------------------------------------

int test_equation_example (Equation_t* expected);

//-------------------------------------------------------------
//! Prints an error and returns -1
//!
//! @return -1
//-------------------------------------------------------------

int test_creating_error ();

//-------------------------------------------------------------
//! Compares two Equation_t objects
//!
//! @param [in]  eq1  Pointer to the first Equation_t
//! @param [in]  eq2  Pointer to the second Equation_t
//!
//! @return 1 if they equal
//-------------------------------------------------------------

int equal_equation_t (Equation_t* eq1, Equation_t* eq2);

#endif // TEST_H
