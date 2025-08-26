#include "common.h"
#include "test/test.h"
#include "input/input.h"
#include "solve/solve.h"
#include "output/output.h"

int main (int argc, char* argv[])
{
    printf ("\n--------------KVADRATKA--------------\n\n");

    test_solve_equation ();

    FILE* stream = stdin;
    check_for_file (argc, argv, &stream);

    Equation_t equation = {.coeffs = {.a = 0,
                                      .b = 0,
                                      .c = 0},
                           .roots  = {.RootsCount = ZERO_SOL,
                                      .x1 = 0,
                                      .x2 = 0}};
    int user_exit = 0;

    while (!(user_exit))
    {
        if (stream == stdin)
        {
            printf ("Enter coefficients\na, b, c: ");
        }

        user_exit = get_input (&equation.coeffs, stream);

        if (stream != stdin)
        {
            printf ("a, b, c: %lg %lg %lg\n",
                     equation.coeffs.a,
                     equation.coeffs.b,
                     equation.coeffs.c);
        }

        if (user_exit)
        {
            break;
        }

        equation.roots.RootsCount = solve_equation (&equation);
        print_answer (&equation.roots);
    }

    printf ("\n------------COMMIT TO GIT------------\n");
    return 0;
}
