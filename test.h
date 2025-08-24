//! @file

#include "common.h"

//---------------------------------------------------------------
//! Tests solve_equation() by inputting different structures with
//! coefficients and expected results and comparing them with
//! given answers
//!
//! @param None
//!
//! @return Number of failed tests
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

int test_equation_example (Equation_t* ptr);
