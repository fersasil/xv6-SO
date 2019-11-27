#include "types.h"
#include "stat.h"
#include "user.h"

#define N  10

void
forktest(void)
{
  int n, pid;

  printf(1, "Teste iniciado, aperte ctrl + p\n");

  for(n = 0; n < N; n++){
    pid = fork(10 * (n + 1)); // Os outros ganham 10 tickets!

    if(pid < 0)
      break;
    if(pid == 0)
      for(; ; ); // Loop infinito
  }

  wait();
  exit();
}

int
main(void)
{
  forktest();
  exit();
}
