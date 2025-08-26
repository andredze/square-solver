#include "../common.h"
#include "solve.h"

SolutionCount_t solve_equation (Equation_t* equation)
{
    if (is_zero (equation->coeffs.a))
    {
        if (is_zero (equation->coeffs.b))
        {
            return is_zero(equation->coeffs.c) ? INF_SOL : ZERO_SOL;
        }
        else // (b != 0)
        {
            solve_linear_eq (equation);
            return ONE_SOL;
        }
    }
    else // (a != 0)
    {
        SolutionCount_t roots_of_quad =  solve_quadratic_eq (equation);
        return roots_of_quad;
    }
    return ROOTSCOUNT_ERROR;
}

int is_zero (double value)
{
    return fabs(value) <= EPS;
}

void solve_linear_eq (Equation_t* equation)
{
    (&equation->roots)->x1 = - equation->coeffs.c / equation->coeffs.b;
}

SolutionCount_t solve_quadratic_eq (Equation_t* eq)
{
    double discr = eq->coeffs.b * eq->coeffs.b - 4 * eq->coeffs.a * eq->coeffs.c;

    if (is_zero (discr))
    {
        (&eq->roots)->x1 = - eq->coeffs.b / (2 * eq->coeffs.a);
        return ONE_SOL;
    }
    else if (less_than_zero (discr))
    {
        return ZERO_SOL;
    }
    else
    {
        double sqrt_discr = sqrt (discr);

        (&eq->roots)->x1 = (- eq->coeffs.b + sqrt_discr) / (2 * eq->coeffs.a);
        (&eq->roots)->x2 = (- eq->coeffs.b - sqrt_discr) / (2 * eq->coeffs.a);

        return TWO_SOL;
    }
    return ROOTSCOUNT_ERROR;
}

int less_than_zero (double value)
{
    return value + EPS < 0;
}

int are_equal (double value1, double value2)
{
    return fabs (value2 - value1) < EPS;
}
