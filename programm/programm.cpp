#include "programm.h"

int run_programm (int argc, char* argv[])
{
    printf ("\n---------------MEOWDRATKA---------------\n\n");

    FILE* stream = stdin;
    if (check_for_file (argc, argv, &stream))
    {
        return 1;
    }

    Equation_t equation = {.coeffs = {.a = 0,
                                      .b = 0,
                                      .c = 0},
                           .roots  = {.RootsCount = ZERO_SOL,
                                      .x1 = 0,
                                      .x2 = 0}};
    int user_active = 1;

    while (user_active)
    {
        if (stream == stdin)
        {
            user_active = get_console_input (&equation.coeffs);
        }
        else
        {
            user_active = get_file_input (&equation.coeffs, stream);
        }
        if (user_active)
        {
            solve_equation (&equation);
            print_answer (&equation.roots);
        }
    }

    printf ("\n-------------COMMIT TO GIT--------------\n");
    return 0;
}
