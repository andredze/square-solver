#include "common.h"
#include "input.h"

int get_input (Equation_t* equation, FILE* stream)
{
    printf ("Coefficients\n");

    int user_exit = 0;

    user_exit = get_coefficient_file ('a', &(equation->a), stream) ||
                get_coefficient_file ('b', &(equation->b), stream) ||
                get_coefficient_file ('c', &(equation->c), stream);

    printf ("\n");
    return user_exit;
}

int get_coefficient_keyboard (char name, double* pointer)
{
    while (1)
    {
        printf ("Enter %c: ", name);
        char line[MAXLEN];

        if (fgets (line, MAXLEN, stdin) != NULL)
        {
            if (sscanf (line, "%lg", pointer) != 1)
            {
                printf ("Viydi i vvedi normalno\n\n");
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int get_coefficient_file (char name, double* pointer, FILE* stream)
{
    while (1)
    {
        printf ("%c: ", name);
        char line[MAXLEN];

        if (fgets (line, MAXLEN, stream) != NULL)
        {
            if (sscanf (line, "%lg", pointer) != 1)
            {
                printf ("Sozday fael normalno\n\n");
            }
            else
            {
                printf ("%s", line);
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
