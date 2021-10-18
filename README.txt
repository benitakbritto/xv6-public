int settickets(int number)
(Side note)
- Added gettickets() for debugging
(Files)
- [UPDATE] Makefile
    CPUS := 1 // Scheduler to run only on 1 CPU
    UPROGS // Add test_settickets user program
- [UPDATE] usys.S
    Add sys call macro
- [UPDATE] syscall.h
    Add sys call number
- [UPDATE] syscall.c
    Add sys call
- [UPDATE] sysproc.c
    Add sys call definition
- [UPDATE] proc.c
    Add sys call implementation
- [UPDATE] proc.h
    Add tickets variable to struct proc
- [UPDATE] user.h
    Add sys call prototype
- [UPDATE] defs.h
    Add sys call prototype
- [ADD] test_settickets.c

