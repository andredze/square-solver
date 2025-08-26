#include "../common.h"
#include "input.h"

void check_for_file (int argc, char* argv[], FILE** stream)
{
    if (argc != 1)
    {
        *stream = fopen (argv[1], "r");
    }
}

int get_input (Coeffs_t* coeffs, FILE* stream)
{
    char line[MAXLEN] = {};
    int user_exit = 0;

    while (1)
    {
        if (fgets (line, MAXLEN, stream) != NULL)
        {
            if (sscanf (line, "%lg %lg %lg", &(coeffs->a), &(coeffs->b), &(coeffs->c)) != 3)
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
