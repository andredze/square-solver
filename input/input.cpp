#include "input.h"

int strcmp (char* str1, const char* str2)
{
    int i = 0;
    while (str1[i] == str2[i] && str1[i] != '\n' && str2[i] != '\n')
    {
        i++;
    }
    if (i > 0)
    {
        if (str1[i - 1] == str2[i - 1])
        {
            return 1;
        }
    }
    return 0;
}

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

int get_console_input (Coeffs_t* coeffs)
{
    printf ("Enter coefficients\na, b, c: ");
    int user_active = get_input (coeffs, stdin);
    return user_active;
}

int get_file_input (Coeffs_t* coeffs, FILE* stream)
{
    int user_active = get_input (coeffs, stream);
    printf ("a, b, c: %lg %lg %lg\n",
                     coeffs->a,
                     coeffs->b,
                     coeffs->c);
    return user_active;
}

int get_input (Coeffs_t* coeffs, FILE* stream)
{
    char line[MAXLEN] = {};
    int user_active = 1;

    while (user_active)
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
        }
    }

    return user_active;
}
