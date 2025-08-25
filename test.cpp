#include "common.h"
#include "test.h"
#include "solve.h"

int test_solve_equation ()
{
    // test_equation_example (a, b, c, x1, x2, RootsCount)
    Equation_t examples[] = {{.a = 1, .b = -5, .c = 6, .x1 = 2, .x2 = 3, .RootsCount = TWO_SOL},
                             {.a = 1, .b = 4, .c = 3, .x1 = -1, .x2 = -3, .RootsCount = TWO_SOL},
                             {.a = 1, .b = 5, .c = 6, .x1 = -2, .x2 = -3, .RootsCount = TWO_SOL},
                             {.a = 0, .b = 1, .c = 6, .x1 = -6, .x2 = 0, .RootsCount = ONE_SOL},
                             {.a = 0, .b = 0, .c = 0, .x1 = 0, .x2 = 0, .RootsCount = INF_SOL},
                             {.a = 0, .b = 0, .c = 5, .x1 = 0, .x2 = 0, .RootsCount = ZERO_SOL},
                             {.a = 0, .b = 0, .c = -14, .x1 = 0, .x2 = 0, .RootsCount = ZERO_SOL},
                             {.a = 1, .b = 2, .c = 1, .x1 = -1, .x2 = 0, .RootsCount = ONE_SOL},
                             {.a = 1, .b = -2.2, .c = 1.21, .x1 = 1.1, .x2 = 0, .RootsCount = ONE_SOL},
                             {.a = 1, .b = 1, .c = 10, .x1 = 0, .x2 = 0, .RootsCount = ZERO_SOL}};
    size_t len = sizeof (examples) / sizeof (examples[0]);

    int failed = 0;
    for (size_t i = 0; i < len; ++i)
    {
        failed += test_equation_example (&(examples[i]));
    }
    printf ("\n");
    return failed;
}

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
        return 1;
    }
    return 0;
}
