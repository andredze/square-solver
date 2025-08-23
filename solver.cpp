#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const double EPS = FLT_EPSILON;

typedef struct Equation {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    SolutionCount_t RootsCount;
} Equation_t;

typedef enum SolutionCount {
    ZERO_SOL,
    ONE_SOL,
    TWO_SOL,
    INF_SOL
} SolutionCount_t;

int test_solve_equation ();

int test_equation_example (double a, double b, double c,
                           double expected_x1, double expected_x2,
                           SolutionCount_t ExpectedRootsCount);

int are_equal (double value1, double value2);

int get_input (double* a, double* b, double* c);

int get_coefficient (char name, double* pointer);

SolutionCount_t solve_equation (double a, double b, double c,
                    double* x1, double* x2);

int is_zero (double value);

int solve_linear_eq (double* x1, double b, double c);

SolutionCount_t solve_quadratic_eq (double* x1, double* x2,
                        double a, double b, double c);

int less_than_zero (double value);

int print_answer (SolutionCount_t RootsCount, double x1, double x2);

int main () {

    printf ("<Square equations solver>\n");

    test_solve_equation ();
    printf ("\n");

    double a = 0, b = 0, c = 0;
    if (get_input (&a, &b, &c) == 0)
    {
        return 0;
    }

    double x1 = 0, x2 = 0;
    SolutionCount_t RootsCount = solve_equation (a, b, c, &x1, &x2);

    print_answer (RootsCount, x1, x2);

    return 0;
}

int test_solve_equation ()
{
    // test_equation_example (a, b, c, x1, x2, RootsCount)
    /*
    test_equation_example (1, -5, 6, 2, 3, TWO_SOL);
    test_equation_example (1, 4, 3, -1, -3, TWO_SOL);
    test_equation_example (1, 5, 6, -2, -3, TWO_SOL);
    test_equation_example (0, 1, 6, -6, 0, ONE_SOL);
    test_equation_example (0, 0, 0, 0, 0, INF_SOL);
    test_equation_example (0, 0, 5, 0, 0, ZERO_SOL);
    test_equation_example (0, 0, -14, 0, 0, ZERO_SOL);
    test_equation_example (1, 2, 1, -1, 0, ONE_SOL);
    test_equation_example (1, -2.2, 1.21, 1.1, 0, ONE_SOL);
    */
    return 0;
}

int test_equation_example (double a, double b, double c,
                           double expected_x1, double expected_x2,
                           SolutionCount_t ExpectedRootsCount)
{
    double x1 = 0, x2 = 0;
    SolutionCount_t RootsCount = solve_equation (a, b, c, &x1, &x2);
    if (!(RootsCount == ExpectedRootsCount &&
        ((are_equal (x1, expected_x1) && are_equal (x2, expected_x2)) ||
         (are_equal (x1, expected_x2) && are_equal (x2, expected_x1)))))
    {
        printf ("Oh no: solve_equation (%lg, %lg, %lg) -> "
                "RootsCount = %d, x1 = %lg, x2 = %lg "
                "(should be RootsCount = %d, x1 = %lg, x2 = %lg)\n",
                a, b, c, RootsCount, x1, x2, ExpectedRootsCount, expected_x1, expected_x2);
        return 0;
    }
    return 1;
}

int are_equal (double value1, double value2)
{
    return fabs (value2 - value1) < EPS;
}

int get_input (double* a, double* b, double* c)
{
    printf ("Coefficients\n");

    return get_coefficient ('a', a) &&
           get_coefficient ('b', b) &&
           get_coefficient ('c', c);
}

int get_coefficient (char name, double* pointer)
{
    printf ("Enter %c: ", name);
    if (scanf ("%lg", pointer) != 1)
    {
        printf ("Error: non-number input at \"%c\"", name);
        return 0;
    }
    return 1;
}

SolutionCount_t solve_equation (double a, double b, double c,
                    double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (is_zero (a))
    {
        if (is_zero (b))
        {
            return is_zero(c) ? INF_SOL : ZERO_SOL;
        }
        else // (b != 0)
        {
            solve_linear_eq (x1, b, c);
            return ONE_SOL;
        }
    }
    else // (a != 0)
    {
        SolutionCount_t roots_of_quad =  solve_quadratic_eq (x1, x2, a, b, c);
        return roots_of_quad;
    }
    return -1;
}

int is_zero (double value)
{
    return fabs(value) <= EPS;
}

int solve_linear_eq (double* x1, double b, double c)
{
    *x1 = -c / b;
    return 0;
}

SolutionCount_t solve_quadratic_eq (double* x1, double* x2,
                        double a, double b, double c)
{
    double discr = b * b - 4 * a * c;

    if (is_zero (discr))
    {
        *x1 = -b / (2 * a);
        return ONE_SOL;
    }
    else if (less_than_zero (discr))
    {
        return ZERO_SOL;
    }
    else
    {
        double sqrt_discr = sqrt (discr);

        *x1 = (-b + sqrt_discr) / (2 * a);
        *x2 = (-b - sqrt_discr) / (2 * a);

        return TWO_SOL;
    }
    return -1;
}

int less_than_zero (double value)
{
    return value + EPS < 0;
}

int print_answer (SolutionCount_t RootsCount, double x1, double x2)
{
    switch (RootsCount)
    {
    case ZERO_SOL:
        printf ("Zero roots");
        break;
    case ONE_SOL:
        printf ("x = %lg", x1);
        break;
    case TWO_SOL:
        printf ("x1 = %lg\nx2 = %lg", x1, x2);
        break;
    case INF_SOL:
        printf ("Infinite amount of roots");
        break;
    default:
        printf ("Error: unexpected \"roots\" return");
        break;
    }
    printf ("\n");
    return 0;
}
