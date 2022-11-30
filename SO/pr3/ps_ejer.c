#include "cabeceras.h"

int main(int argc, char** argv){

    pid_t pid = getpid();
    pid_t ppid = getppid();

    pid_t pgid = getpgid(pid);
    pid_t sid = getsid(pid);

    if(errno){
        fprintf(stderr, "Errno raised\n");
        return errno;
    }else{
        printf("PID: %d\n", pid);
        printf("PPID: %d\n", ppid);
        printf("PGID: %d\n", pgid);
        printf("SID: %d\n", sid);

    }
    return 0;
}
