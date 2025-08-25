//! @file

#include "common.h"

//-----------------------------------------------------
//! Gets coefficients for ax2 + bx + c = 0 equation
//! from keyboard
//!
//! @param  equation  Pointer to a Equation_t, containing
//!                   a, b, c -coefficients, roots x1, x2
//!                   and number of roots;
//! @param  stream  Pointer to a FILE, redirecting
//!                 to the file stream
//!
//! @return 1 if user wants to exit. Else 0
//!
//! @note   Prints an error in case of a wrong input and
//!         allows to re-enter; EOF to exit the function
//-----------------------------------------------------

int get_input (Equation_t* equation, FILE* stream);
