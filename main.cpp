#include "common.h"
#include "test.h"
#include "input.h"
#include "solve.h"
#include "output.h"

int main () {

    printf ("<Square equations solver>\n");

    test_solve_equation ();

    Equation_t equation = {0, 0, 0, 0, 0, ZERO_SOL};

    FILE* file_stream = fopen ("file.txt", "r");

    while (!(get_input (&equation, file_stream)))
    {
        equation.RootsCount = solve_equation (&equation);
        print_answer (&equation);
    }

    return 0;
}
