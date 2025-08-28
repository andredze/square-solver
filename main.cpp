#include "common.h"
#include "test/test.h"
#include "programm/programm.h"

#ifdef DEBUG_MODE
int main (int argc, char* argv[])
{
    printf ("Input debug mode: ");
    char debug_mode[MAXLEN] = "";
    scanf ("%s", debug_mode);

    if (strcmp (debug_mode, "TEST"))
    {
        test_solve_equation ();
    }
    else if (strcmp (debug_mode, "RUN"))
    {
        run_programm (argc, argv);
    }
    else
    {
        printf ("Error: unknown debugging command\n");
    }
    return 0;
}

#else
int main (int argc, char* argv[])
{
    return run_programm (argc, argv);
}
#endif
