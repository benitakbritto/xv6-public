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
    printf(1, "argv[1] = %d\n", atoi(argv[1]));
    res = settickets(atoi(argv[1]));
    printf(1, "Return value = %d\n", res);
    exit();
}