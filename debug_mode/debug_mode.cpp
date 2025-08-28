#include "debug_mode.h"

int get_debug_mode (char* debug_mode)
{
    printf ("Input debug mode: ");

    if (fgets (debug_mode, MAXLEN, stdin) == NULL)
    {
        printf ("Input the command\n");
        return 1;
    }
    char* ptr_enter = strchr (debug_mode, '\n');
    *ptr_enter = '\0';
    return 0;
}
