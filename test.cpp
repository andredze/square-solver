#include "common.h"
#include "test.h"
#include "solve.h"

//---------------------------------------------------------------
//! Tests solve_equation() by inputting different structures with
//! coefficients and expected results and comparing them with
//! given answers
//!
//! @param None
//!
//! @return Number of failed tests
//---------------------------------------------------------------

int test_solve_equation ()
{
    // test_equation_example (a, b, c, x1, x2, RootsCount)
    Equation_t examples[] = {{1, -5, 6, 2, 3, TWO_SOL},
                             {1, 4, 3, -1, -3, TWO_SOL},
                             {1, 5, 6, -2, -3, TWO_SOL},
                             {0, 1, 6, -6, 0, ONE_SOL},
                             {0, 0, 0, 0, 0, INF_SOL},
                             {0, 0, 5, 0, 0, ZERO_SOL},
                             {0, 0, -14, 0, 0, ZERO_SOL},
                             {1, 2, 1, -1, 0, ONE_SOL},
                             {1, -2.2, 1.21, 1.1, 0, ONE_SOL},
                             {1, 1, 10, 0, 0, ZERO_SOL}};
    int failed = 0;
    for (int i = 0; i < 10; ++i)
    {
        failed += !test_equation_example (&(examples[i]));
    }
    return failed;
}

//---------------------------------------------------------------
//! Tests solve_equation with one example of equation
//!
//! @param  expected  pointer to a Equation_t, containing
//!         a, b, c -coefficients, referenced roots x1, x2
//!         and referenced number of roots;
//!
//! @return 0 in case of a mistake; 1 if everything is fine
//---------------------------------------------------------------

int test_equation_example (Equation_t* expected)
{
    Equation_t equation = {expected->a, expected->b, expected->c, 0, 0, ZERO_SOL};
    equation.RootsCount = solve_equation (&equation);
    if (!(equation.RootsCount == expected->RootsCount &&
        ((are_equal (equation.x1, expected->x1) && are_equal (equation.x2, expected->x2)) ||
         (are_equal (equation.x1, expected->x2) && are_equal (equation.x2, expected->x1)))))
    {
        printf ("Oh no: solve_equation (%lg, %lg, %lg) -> "
                "RootsCount = %d, x1 = %lg, x2 = %lg "
                "(should be RootsCount = %d, x1 = %lg, x2 = %lg)\n",
                expected->a, expected->b, expected->c, equation.RootsCount, equation.x1, equation.x2,
                 expected->RootsCount, expected->x1, expected->x2);
        return 0;
    }
    return 1;
}
