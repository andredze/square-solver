#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const double EPS = FLT_EPSILON;

typedef enum SolutionCount {
    ZERO_SOL,
    ONE_SOL,
    TWO_SOL,
    INF_SOL,
    ROOTSCOUNT_ERROR
} SolutionCount_t;

typedef struct Equation {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    SolutionCount_t RootsCount;
} Equation_t;

int test_solve_equation ();

int test_equation_example (Equation_t* ptr);

int are_equal (double value1, double value2);

int get_input (Equation_t* equation);

int get_coefficient (char name, double* pointer);

SolutionCount_t solve_equation (Equation_t* equation);

int is_zero (double value);

int solve_linear_eq (Equation_t* equation);

SolutionCount_t solve_quadratic_eq (Equation_t* equation);

int less_than_zero (double value);

int print_answer (Equation_t* equation);

int main () {

    printf ("<Square equations solver>\n");

    test_solve_equation ();
    printf ("\n");

    Equation_t equation = {0, 0, 0, 0, 0, ZERO_SOL};

    if (get_input (&equation) == 0)
    {
        return 0;
    }

    equation.RootsCount = solve_equation (&equation);

    print_answer (&equation);

    return 0;
}

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
    int i;
    for (i = 0; i < 10; ++i)
    {
        test_equation_example (&(examples[i]));
    }
    return 0;
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
        return 0;
    }
    return 1;
}

int are_equal (double value1, double value2)
{
    return fabs (value2 - value1) < EPS;
}

int get_input (Equation_t* equation)
{
    printf ("Coefficients\n");

    return get_coefficient ('a', &(equation->a)) &&
           get_coefficient ('b', &(equation->b)) &&
           get_coefficient ('c', &(equation->c));
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

int print_answer (Equation_t* equation)
{
    switch (equation->RootsCount)
    {
    case ZERO_SOL:
        printf ("Zero roots");
        break;
    case ONE_SOL:
        printf ("x = %lg", equation->x1);
        break;
    case TWO_SOL:
        printf ("x1 = %lg\nx2 = %lg", equation->x1, equation->x2);
        break;
    case INF_SOL:
        printf ("Infinite amount of roots");
        break;
    case ROOTSCOUNT_ERROR:
        printf ("Error: unexpected \"RootsCount\" return");
        break;
    default:
        printf ("Error during switch (RootsCount)");
        break;
    }
    printf ("\n");
    return 0;
}
