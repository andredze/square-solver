#include "common.h"
#include "input.h"

int get_input (Equation_t* equation, FILE* stream)
{
    char line[MAXLEN];
    int user_exit = 0;

    while (1)
    {
        if (fgets (line, MAXLEN, stream) != NULL)
        {
            if (sscanf (line, "%lg %lg %lg", &(equation->a), &(equation->b), &(equation->c)) != 3)
            {
                printf ("Viydi i vvedi normalno\n\n");
            }
            else
            {
                break;
            }
        }
        else
        {
            user_exit = 1;
            break;
        }
    }

    return user_exit;
}
