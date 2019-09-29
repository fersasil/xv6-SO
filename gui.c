#include "types.h"
#include "stat.h"
#include "user.h"

volatile void take_time(){
    // volatile int l;
    // unsigned long long int gui = 0;
    // gui++;
    
    // for(int i = 0; i < 1000000; i++)
    //     for(int j = 0; j < 100000; j++)
    //         gui++;
    
    // printf(1, "fim %d\n", gui);

    // sleep(500);
    sleep(1000);
    printf(1, "ok\n");

}

int main(){
    int i;
    printf(1, "Ola mundo\n");
    
    for(i = 0; i < 5; i++){
        int pid = fork(50);
        if(pid > 0){
        //É o filho!
            
            printf(1, "Eu sou o filho!\n");

            take_time();
            
            wait();
        }
        else if(pid == 0){
            exit(); //É o pai
        }
    }

    


    exit();
}