#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

/* Temp test user function */
int
main(int argc, char *argv[])
{
    int res;
    printf(1, "test_settickets.c was invoked\n");
    res = settickets(atoi(argv[1]));
    printf(1, "Return value of settickets() = %d\n", res);
    
    int rc = fork();
    if (rc < 0)
    {
        printf(1, "forked failed \n");
    }
    else if (rc == 0)
    {
        printf(1, "CHILD tickets = %d\n", gettickets());
    }
    else
    {
        wait();
        printf(1, "PARENT tickets = %d\n", gettickets());
    }
    exit();
}