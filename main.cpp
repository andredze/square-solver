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

    get_input (&equation);

    equation.RootsCount = solve_equation (&equation);

    print_answer (&equation);

    return 0;
}
