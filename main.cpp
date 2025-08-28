#include "common.h"
#include "test/test.h"
#include "programm/programm.h"
#include "debug_mode/debug_mode.h"

int main (int argc, char* argv[])
{
#ifdef DEBUG_MODE
    char debug_mode[MAXLEN] = "";
    get_debug_mode (debug_mode);

    if (strequal (debug_mode, "TEST") == 0)
    {
        test_solve_equation ();
    }
    else if (strequal (debug_mode, "RUN") == 0)
    {
#endif
        run_programm (argc, argv);
#ifdef DEBUG_MODE
    }
    else
    {
        printf ("Error: unknown debugging command\n");
    }
#endif /* DEBUG_MODE */
    return 0;
}
