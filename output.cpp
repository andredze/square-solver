#include "common.h"
#include "output.h"

void print_answer (Equation_t* equation)
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
    printf ("\n\n");
}
