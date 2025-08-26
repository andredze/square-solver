#include "solve.h"

void solve_equation (Equation_t* eq)
{
    double a = eq->coeffs.a;
    double b = eq->coeffs.b;
    double c = eq->coeffs.c;

    if (is_zero (a))
    {
        if (is_zero (b))
        {
            (&eq->roots)->RootsCount = is_zero(c) ? INF_SOL : ZERO_SOL;
            return;
        }
        else // (b != 0)
        {
            solve_linear_eq (eq);
            (&eq->roots)->RootsCount = ONE_SOL;
            return;
        }
    }
    else // (a != 0)
    {
        solve_quadratic_eq (eq);
        return;
    }
    (&eq->roots)->RootsCount = ROOTSCOUNT_ERROR;
}

int is_zero (double value)
{
    return fabs(value) <= EPS;
}

void solve_linear_eq (Equation_t* eq)
{

    double b = eq->coeffs.b;
    double c = eq->coeffs.c;
    (&eq->roots)->x1 = - c / b;
}

void solve_quadratic_eq (Equation_t* eq)
{
    double a = eq->coeffs.a;
    double b = eq->coeffs.b;
    double c = eq->coeffs.c;

    double discr = b * b - 4 * a * c;

    if (is_zero (discr))
    {
        (&eq->roots)->x1 = - b / (2 * a);
        (&eq->roots)->RootsCount = ONE_SOL;
        return;
    }
    else if (less_than_zero (discr))
    {
        (&eq->roots)->RootsCount = ZERO_SOL;
        return;
    }
    else
    {
        double sqrt_discr = sqrt (discr);

        (&eq->roots)->x1 = (- b + sqrt_discr) / (2 * a);
        (&eq->roots)->x2 = (- b - sqrt_discr) / (2 * a);

        (&eq->roots)->RootsCount = TWO_SOL;
        return;
    }
    (&eq->roots)->RootsCount = ROOTSCOUNT_ERROR;
}

int less_than_zero (double value)
{
    return value + EPS < 0;
}

int are_equal (double value1, double value2)
{
    return fabs (value2 - value1) < EPS;
}
