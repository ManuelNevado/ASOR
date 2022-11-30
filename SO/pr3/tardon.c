#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    pid_t pid = getpid();
    printf("PID: %d\n",pid);
    for(int i =0;i<100000000000;i++){
        printf("\rCount: %d",i);
        fflush(stdout);
    }
    printf("\n");
    return 0;
}

