// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fs.h"

// /* Temp test user function */
// int
// main(int argc, char *argv[])
// {
//     int res;
//     printf(1, "test_settickets.c was invoked\n");
//     res = settickets(atoi(argv[1]));
//     printf(1, "Return value of settickets() = %d\n", res);
    
//     int rc = fork();
//     if (rc < 0)
//     {
//         printf(1, "forked failed \n");
//     }
//     else if (rc == 0)
//     {
//         printf(1, "CHILD tickets = %d\n", gettickets());
//     }
//     else
//     {
//         wait();
//         printf(1, "PARENT tickets = %d\n", gettickets());
//     }
//     exit();
// }

#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
#define PROC 5

void spin()
{
  int i = 0;
  int j = 0;
  int k = 0;
  for(i = 0; i < 50; ++i)
  {
    for(j = 0; j < 10000000; ++j)
    {
      k = j % 10;
      k = k + 1;
    }
  }
  printf(1, "Exiting spin()\n");
}


int
main(int argc, char *argv[])
{
   struct pstat st;
   int count = 0;
   int i = 0;
   int pid[NPROC];
   printf(1,"Spinning...\n");
   while(i < PROC)
   {
      pid[i] = fork();
      if(pid[i] == 0) // child
	    {
	        spin();
            //printf(1, "child going to exit\n");
            exit();
      }
      i++;
   }
   sleep(500);
   //spin();
   if(getpinfo(&st) == 0)
   {
       printf(1, "getpinfo() succeeded!\n");
   }
   else
   {
    printf(1, "XV6_SCHEDULER\t FAILED\n");
    exit();
   }

   printf(1, "\n**** PInfo ****\n");
   for(i = 0; i < NPROC; i++) {
      if (st.inuse[i]) {
               count++;
         printf(1, "pid: %d tickets: %d ticks: %d\n", st.pid[i], st.tickets[i], st.ticks[i]);
      }
   }
   for(i = 0; i < PROC; i++)
   {
        //printf(1, "Killing pid [%d]\n", pid[i]);
        kill(pid[i]);
   }
   while (wait() > 0);
   printf(1,"Number of processes in use %d\n", count);
   
   if(count == 8)
   {
    printf(1, "XV6_SCHEDULER\t SUCCESS\n");
   }
   else
   {
    printf(1, "XV6_SCHEDULER\t FAILED\n");
   }
    

   exit();
}