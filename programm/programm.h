//! @file

#ifndef PROGRAMM_H
#define PROGRAMM_H

#include "../common.h"
#include "../input/input.h"
#include "../solve/solve.h"
#include "../output/output.h"

//--------------------------------------------
//! Runs the main programm
//!
//! @param  [in]  argc  Amount of arguments given in terminal
//! @param  [in]  argv  Pointer to an array with terminal arguments
//!
//! @return 0 if no errors
//--------------------------------------------

int run_programm (int argc, char* argv[]);

#endif
