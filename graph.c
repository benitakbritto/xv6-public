#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
#define PROC 3

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
}

int
main(int argc, char *argv[])
{
   struct pstat st;
   int i = 0;
   printf(1,"Spinning...\n");
   for (int i = 0; i < 3; i++)
   {
      int rc = fork();

      if (rc == 0) // child
      {
          settickets(3 - i);
          spin();
          exit();
      }
   }

   sleep(500);
   if(getpinfo(&st) == 0)
   {
   }
   else
   {
    printf(1, "XV6_SCHEDULER\t FAILED\n");
    exit();
   }

   printf(1, "\n**** PInfo ****\n");
   for(i = 3; i < NPROC; i++) 
   {
      if (st.inuse[i]) 
      {
         printf(1, "pid: %d tickets: %d ticks: %d\n", st.pid[i], st.tickets[i], st.ticks[i]);
      }
   }
   
   exit();
}