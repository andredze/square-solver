#include "common.h"
#include "test.h"
#include "input.h"
#include "solve.h"
#include "output.h"

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
