#include "common.h"
#include "solve.h"

SolutionCount_t solve_equation (Equation_t* equation)
{
    if (is_zero (equation->a))
    {
        if (is_zero (equation->b))
        {
            return is_zero(equation->c) ? INF_SOL : ZERO_SOL;
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

int solve_linear_eq (Equation_t* equation)
{
    equation->x1 = -equation->c / equation->b;
    return 0;
}

SolutionCount_t solve_quadratic_eq (Equation_t* equation)
{
    double discr = equation->b * equation->b - 4 * equation->a * equation->c;

    if (is_zero (discr))
    {
        equation->x1 = - equation->b / (2 * equation->a);
        return ONE_SOL;
    }
    else if (less_than_zero (discr))
    {
        return ZERO_SOL;
    }
    else
    {
        double sqrt_discr = sqrt (discr);

        equation->x1 = (- equation->b + sqrt_discr) / (2 * equation->a);
        equation->x2 = (- equation->b - sqrt_discr) / (2 * equation->a);

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
