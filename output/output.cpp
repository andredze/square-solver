#include "output.h"

void print_answer (Roots_t* roots)
{
    assert(roots != NULL);

    switch (roots->RootsCount)
    {
    case ZERO_SOL:
        printf ("Zero roots");
        break;
    case ONE_SOL:
        printf ("x = %lg", roots->x1);
        break;
    case TWO_SOL:
        printf ("x1 = %lg\nx2 = %lg", roots->x1, roots->x2);
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
