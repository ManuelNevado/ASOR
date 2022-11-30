#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main(){
    setuid(2000);
    if(errno){
        printf("Error number: %d\n",errno);
        perror("Error type: ");
    }
    return 1;
}

