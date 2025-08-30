#include "test.h"

int test_solve_equation ()
{
    int passed = 0;
    int tests_count = 0;
    char line[MAXLEN] = {0};

    FILE* stream = fopen ("./test/tests.txt", "r");

    Equation_t equation = {.coeffs = {.a = 0,
                                      .b = 0,
                                      .c = 0},
                           .roots  = {.RootsCount = ZERO_SOL,
                                      .x1 = 0,
                                      .x2 = 0}};

    while (fgets (line, MAXLEN, stream) != NULL)
    {
        if (sscanf (line, "%lg %lg %lg %d %lg %lg",
                    &equation.coeffs.a, &equation.coeffs.b, &equation.coeffs.c,
                    (int *) &equation.roots.RootsCount,
                    &equation.roots.x1, &equation.roots.x2) == 6)
        {
            passed += !test_equation_example (&equation);
        }
        else
        {
            return test_creating_error ();
        }
        tests_count += 1;
    }

    printf ("\nPassed tests: %d/%d\n", passed, tests_count);

    return 0;
}

int test_equation_example (Equation_t* exp)
{
    assert(exp != NULL);

    double a = exp->coeffs.a;
    double b = exp->coeffs.b;
    double c = exp->coeffs.c;

    Equation_t real = {{a, b, c}, {ZERO_SOL, 0, 0}};

    solve_equation (&real);

    double x1 = real.roots.x1;
    double x2 = real.roots.x2;
    SolutionCount_t RootsCount = real.roots.RootsCount;

    double x1_ref = exp->roots.x1;
    double x2_ref = exp->roots.x2;
    SolutionCount_t RootsCount_ref = exp->roots.RootsCount;

    if (!(equal_equation_t (exp, &real)))
    {
        printf ("Oh no: solve_equation (%lg, %lg, %lg) -> "
                "RootsCount = %d, x1 = %lg, x2 = %lg "
                "(should be RootsCount = %d, x1 = %lg, x2 = %lg)\n",
                a, b, c, RootsCount, x1, x2, RootsCount_ref, x1_ref, x2_ref);
        return 1;
    }
    return 0;
}

int test_creating_error ()
{
    printf ("\nError in creating texts.txt\n");
    return 1;
}

int equal_equation_t (Equation_t* eq1, Equation_t* eq2)
{
    assert(eq1 != NULL);
    assert(eq2 != NULL);
    assert(eq1 != eq2);

    double x1 = eq1->roots.x1;
    double x2 = eq1->roots.x2;
    SolutionCount_t RootsCount = eq1->roots.RootsCount;

    double x1_ref = eq2->roots.x1;
    double x2_ref = eq2->roots.x2;
    SolutionCount_t RootsCount_ref = eq2->roots.RootsCount;

    return RootsCount == RootsCount_ref &&
          ((are_equal (x1, x1_ref) && are_equal (x2, x2_ref)) ||
           (are_equal (x1, x2_ref) && are_equal (x2, x1_ref)));
}
