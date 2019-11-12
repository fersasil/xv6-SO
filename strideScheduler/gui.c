#include "types.h"
#include "stat.h"
#include "user.h"

#define N  5

void
forktest(void)
{
  int n, pid;

  printf(1, "Teste iniciado, aperte ctrl + p\n");

  for(n = 0; n < N; n++){
    if(n == 0)
      pid = fork(50); // Primeiro processo ganha 50 tickets
    else{
      pid = fork(10); // Os outros ganham 10 tickets!
    }
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
