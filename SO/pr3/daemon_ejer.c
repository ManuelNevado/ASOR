#include "cabeceras.h"

void father_process(){
        pid_t pid = getpid();
        printf("PID Father: %d\n", pid);

        pid_t ppid = getppid();

        pid_t pgid = getpgid(pid);
        pid_t sid = getsid(pid);

        if(errno){
            fprintf(stderr, "Errno raised\n");
            return errno;
        }else{
            printf("PPID of the father: %d\n", ppid);
            printf("PGID of the father: %d\n", pgid);
            printf("SID of the father: %d\n", sid);
        }   
    
}

void daemon_process(){
    usleep(500);
    //Getting the pid
    pid_t pid = getpid();
    pid_t ppid = getppid();
    
    //Setting a new prrocess group ID
    //int setpgid(pid_t pid, pid_t pgid);
    pid_t sid = setsid();
    
    if(errno){
        fprintf(stderr, "Errno raised: %d\n", errno);
        return errno;
    }else{
        printf("PID: %d\n", pid);
        printf("PPID: %d\n", ppid);
        printf("PGID: %d\n", getpgid(pid));
        printf("SID: %d\n",sid); 

    }

}

int main(int argc, char** argv){

    pid_t forked = fork();
    if(forked==-1){
        perror("Error en fork\n");
        return 1;
    }    
    if(forked!=0){
        father_process();
    }else{
        daemon_process();
    }
    return 0;
}
