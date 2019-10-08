#include "types.h"
#include "stat.h"
#include "user.h"

#define N  5

void
forktest(void)
{
  int n, pid;

  printf(1, "fork test\n");

  for(n=0; n<N; n++){
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

  if(n == N){
    printf(1, "fork claimed to work %d times!\n", N);
    exit();
  }

  for(; n > 0; n--){
    if(wait() < 0){
      printf(1, "wait stopped early\n");
      exit();
    }
  }

  if(wait() != -1){
    printf(1, "wait got too many\n");
    exit();
  }

  printf(1, "fork test OK\n");
  exit();
}

int
main(void)
{
  forktest();
  exit();
}
