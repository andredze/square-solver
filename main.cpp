#include "common.h"
#include "test.h"
#include "input.h"
#include "solve.h"
#include "output.h"

int main () {

    printf ("<Square equations solver>\n");

    test_solve_equation ();

    Equation_t equation = {0, 0, 0, 0, 0, ZERO_SOL};

    FILE* stream = stdin;

    int is_from_file = 0;

    if (is_from_file)
    {
        stream = fopen ("file.txt", "r");
    }

    int user_exit = 0;

    while (!(user_exit))
    {
        if (stream == stdin)
        {
            printf ("Coefficients\nEnter a, b, c: ");
        }

        user_exit = get_input (&equation, stream);
        if (stream != stdin)
        {
            printf ("a, b, c: %lg %lg %lg\n", equation.a, equation.b, equation.c);
        }

        if (user_exit)
        {
            break;
        }

        equation.RootsCount = solve_equation (&equation);
        print_answer (&equation);
    }

    return 0;
}
