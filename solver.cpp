#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const double EPS = FLT_EPSILON;

typedef enum SolutionCount {
    ZERO_SOL,
    ONE_SOL,
    TWO_SOL,
    INF_SOL
} SolutionCount_t;

int get_input (double* a, double* b, double* c);

int get_coefficient (char name, double* pointer);

SolutionCount_t solve_equation (double a, double b, double c,
                    double* x1, double* x2);

int is_zero (double value);

int solve_linear_eq (double* x1, double b, double c);

SolutionCount_t solve_quadratic_eq (double* x1, double* x2,
                        double a, double b, double c);

int less_than_zero (double value);

int print_answer (SolutionCount_t roots, double x1, double x2);

int main () {

    printf ("<Square equations solver>\n\n");

    double a = 0, b = 0, c = 0;
    if (get_input (&a, &b, &c) == -1)
    {
        return 0;
    }

    double x1 = 0, x2 = 0;
    SolutionCount_t roots = solve_equation (a, b, c, &x1, &x2);

    print_answer (roots, x1, x2);

    return 0;
}

int get_input (double* a, double* b, double* c)
{
    printf ("Coefficients\n");

    get_coefficient ('a', a);
    get_coefficient ('b', b);
    get_coefficient ('c', c);

    return 0;
}

int get_coefficient (char name, double* pointer)
{
    printf ("Enter %c: ", name);
    if (scanf ("%lg", pointer) != 1)
    {const double EPS = FLT_EPSILON;
        printf ("Error: non-number input at \"%c\"", name);
        return -1;
    }
    return 0;
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
}

int is_zero (double n)
{
    return fabs(n) <= EPS;
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
}

int less_than_zero (double n)
{
    return n + EPS < 0;
}

int print_answer (SolutionCount_t roots, double x1, double x2)
{
    switch (roots)
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
    return 0;
}
