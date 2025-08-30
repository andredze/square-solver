//! @file

#ifndef INPUT_H
#define INPUT_H

#include "../common.h"

//----------------------------------------------------------------
//! Checks if strings are equal jopa
//!
//! @param [in]  str1  first string
//! @param [in]  str2  second string
//!
//! @return 1 if they are equal
//----------------------------------------------------------------

int strcmpr (const char* str1, const char* str2);

//-------------------------------------------------------------------
//! Checks terminal input for file. Sets stream to file
//! if it was given
//!
//! @param  [in]  argc  Amount of arguments given in terminal
//! @param  [in]  argv  Pointer to an array with terminal arguments
//! @param  [out]  stream  Pointer to a FILE*
//!
//! @return 0 if it is fine
//-------------------------------------------------------------------

int check_for_file (int argc, char* argv[], FILE** stream);

//------------------------------------------------------------------
//! Prints message to the user and gets the input from console
//!
//! @param  [in]  coeffs  Pointer to a Coeffs_t containing coefficients
//!
//! @return 0 if user wants to exit
//------------------------------------------------------------------

int get_console_input (Coeffs_t* coeffs);

//------------------------------------------------------------------
//! Prints message to the user and gets the input from file
//!
//! @param  [in]  coeffs  Pointer to a Coeffs_t containing coefficients
//! @param  [in]  stream  file_stream
//!
//! @return 0 if user wants to exit
//------------------------------------------------------------------

int get_file_input (Coeffs_t* coeffs, FILE* stream);

//-----------------------------------------------------
//! Gets coefficients for ax2 + bx + c = 0 equation
//! from keyboard
//!
//! @param  coeffs  Pointer to a Coeffs_t, containing
//!                 a, b, c -coefficients;
//! @param  stream  Pointer to a FILE, redirecting
//!                 to the file stream
//!
//! @return 0 if user wants to exit. Else 1
//!
//! @note   Prints an error in case of a wrong input and
//!         allows to re-enter; EOF to exit the function
//-----------------------------------------------------

int get_input (Coeffs_t* coeffs, FILE* stream);

#endif // INPUT_H
