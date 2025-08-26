#include "input.h"

int check_for_file (int argc, char* argv[], FILE** stream)
{
    if (argc != 1)
    {
        *stream = fopen (argv[1], "r");
        if (*stream == NULL)
        {
            printf ("Error: cannot open %s\n", argv[1]);
            return 1;
        }
    }
    return 0;
}

int get_input (Coeffs_t* coeffs, FILE* stream)
{
    char line[MAXLEN] = {};
    int user_active = 1;

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
            user_active = 0;
            break;
        }
    }

    return user_active;
}
