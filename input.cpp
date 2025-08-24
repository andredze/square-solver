#include "common.h"
#include "input.h"

void get_input (Equation_t* equation)
{
    printf ("Coefficients\n");

    get_coefficient ('a', &(equation->a));
    get_coefficient ('b', &(equation->b));
    get_coefficient ('c', &(equation->c));
    printf ("\n");
}

void get_coefficient (char name, double* pointer)
{
    while (1)
    {
        printf ("Enter %c: ", name);
        if (scanf ("%lg", pointer) != 1 || getchar () != '\n')
        {
            shavatb_govno ();
            printf ("Debil, viydi i vvedi normalno\n\n");
        }
        else
        {
            break;
        }
    }
}

void shavatb_govno ()
{
    int c = 0;
    while ((c = getchar ()) != '\n')
    {
        ;
    }
}
