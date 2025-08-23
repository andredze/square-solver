#include "common.h"
#include "input.h"

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
