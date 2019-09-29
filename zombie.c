// Create a zombie process that
// must be reparented at exit.

#include "types.h"
#include "stat.h"
#include "user.h"
#include "lottery_scheduler.h"

int
main(void)
{
  if(fork(MIN_TICKETS) > 0)
    sleep(5);  // Let child exit before parent.
  exit();
}
