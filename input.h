//! @file

#include "common.h"

//-----------------------------------------------------
//! Gets coefficients for ax2 + bx + c = 0 equation
//! from keyboard
//!
//! @param  equation  Pointer to a Equation_t, containing
//!                   a, b, c -coefficients, roots x1, x2
//!                   and number of roots;
//!
//! @note   Prints an error in case of a wrong input and
//!         allows to re-enter
//-----------------------------------------------------

void get_input (Equation_t* equation);

//-------------------------------------------------------
//! Prints message to the user and gets
//! the coefficient from keyboard
//!
//! @param [in]  name  Name of the coefficient
//! @param [out]  pointer  A pointer to the coefficient
//-------------------------------------------------------

void get_coefficient (char name, double* pointer);

//-----------------------------------------------------------
//! Removes input from the queue if it doesn't fit the format
//-----------------------------------------------------------

void shavatb_govno ();
