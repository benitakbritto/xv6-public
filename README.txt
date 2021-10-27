**************************
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

**************************
int getpinfo(struct pstat *)

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
- [UPDATE] user.h
    Add sys call prototype
- [UPDATE] defs.h
    Add sys call prototype

**************************
Proportional Share Scheduler:
- [UPDATE] proc.c
    scheduler() function:
    - loop over the process ticket number of times

**************************
Null Deference:
- [UPDATE] Makefile
    Set the -Ttext section of user programs to point to one page higher in the address space
    As the page size is 4096 (0x1000) bytes and the old -Ttext section pointed at 0, the new
    section will point at 0x1000 instead. 

- [UPDATE] exec.c
    Call make to allocuvm() in load program to memory section to start 1 page size higher than 
    it usually did (hence making the first page invalid).
    This is for parent processes.

- [UPDATE] vm.c
    In copyuvm, start allocating space for the child process one page higher.
    This is for child processes. 