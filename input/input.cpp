#include "input.h"

int strcmpr (const char *str1, const char *str2)
{
    assert(str1 != str2);
    assert(str1 != NULL);
    assert(str2 != NULL);

    for (; *str1 == *str2 && *str1 != '\0' && *str2 != '\0'; str1++, str2++) {}
        // do nothing;
    return *str1 - *str2;
}

int check_for_file (int argc, char* argv[], FILE** stream)
{
    assert(stream != NULL);
    assert(argv != NULL);

    if (argc == 1)
    {
        return 0;
    }
    *stream = fopen (argv[1], "r");
    if (*stream == NULL)
    {
        printf ("Error: cannot open %s\n", argv[1]);
        return 1;
    }
    return 0;
}

int get_console_input (Coeffs_t* coeffs)
{
    assert(coeffs != NULL);

    printf ("Enter coefficients\na, b, c: ");
    int user_active = get_input (coeffs, stdin);
    return user_active;
}

int get_file_input (Coeffs_t* coeffs, FILE* stream)
{
    assert(coeffs != NULL);
    assert(stream != NULL);

    int user_active = get_input (coeffs, stream);

    if (user_active != EOF)
    {
        printf ("a, b, c: %lg %lg %lg\n",
                     coeffs->a,
                     coeffs->b,
                     coeffs->c);
    }
    return user_active;
}

int get_input (Coeffs_t* coeffs, FILE* stream)
{
    assert(coeffs != NULL);
    assert(stream != NULL);

    char line[MAXLEN] = {};
    int user_active = 1;

    while (user_active)
    {
        if (fgets (line, MAXLEN, stream) == NULL) // if EOF is reached
        {
            return 0;
        }
        if (sscanf (line, "%lg %lg %lg",
                    &(coeffs->a), &(coeffs->b), &(coeffs->c)) != 3)
        {
            if (stream == stdin)
            {
                printf ("\nViydi i vvedi normalno\n");
                printf ("Enter cooefficients\na, b, c: ");
            }
            else
            {
                printf ("Incorrect file structure. Check \"README\"\n");
                return EOF;
            }
        }
        else // Input is correct
        {
            break;
        }
    }

    return user_active;
}
