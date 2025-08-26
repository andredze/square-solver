//! @file

#ifndef SOLVE_H
#define SOLVE_H

#include "../common.h"

//---------------------------------------------------------------------------
//! Solves a square equation ax2 + bx + c = 0 (or linear in case of a == 0)
//!
//! @param  equation  pointer to a Equation_t, containing
//!                   a, b, c -coefficients, roots x1, x2
//!                   and number of roots;
//!
//! @return SolutionCount_t object, encountering number of roots
//---------------------------------------------------------------------------

void solve_equation (Equation_t* equation);

//-----------------------------------------------------
//! Checks if the number is equal to zero (within EPS)
//!
//! @param [in]  value  Any number
//!
//! @return 1 if number is zero; 0 if not
//-----------------------------------------------------

int is_zero (double value);

//----------------------------------------------------
//! Solves a linear equation bx + c = 0
//!
//! @param  equation  pointer to a Equation_t, containing
//!                   a, b, c -coefficients, roots x1, x2
//!                   and number of roots;
//----------------------------------------------------

void solve_linear_eq (Equation_t* equation);

//------------------------------------------------------
//! Solves a square equation with non-zero a-coefficient
//!
//! @param  equation  pointer to a Equation_t, containing
//!                   a, b, c -coefficients, roots x1, x2
//!                   and number of roots;
//!
//! @return Number of roots
//------------------------------------------------------

void solve_quadratic_eq (Equation_t* equation);

//-------------------------------------------------
//! Checks if number is less than zero
//!
//! @param [in]  value  Verifiable number
//!
//! @return 1 if number is less than zero; 0 if not
//-------------------------------------------------

int less_than_zero (double value);

//-------------------------------------------------
//! Checks if two numbers are equal
//!
//! @param [in]  value1  First number
//! @param [in]  value2  Second number
//!
//! @return 1 if numbers are equal; 0 if not
//-------------------------------------------------

int are_equal (double value1, double value2);

#endif // SOLVE_H
