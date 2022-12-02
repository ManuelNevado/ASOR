#include "cabeceras.h"

void daemon_fun(int argc, char** argv);

int main(int argc, char** argv){
    
    if(argc < 2){
        printf("Low number of arguments\n");
        printf("The executable must be followed by the command you want to execute\n");
        return 1;
    }

    pid_t forked = fork();

    if(forked == -1){
        perror("ERRRO\n");
        return 1;
    }if(forked!=0){
        return 0;
    }else{
        //Se lanza el daemon
        daemon(argc, argv);
    }

    return 0;
}

void daemon_fun(int argc, char** argv){

    char* arglist[argc-1+1];
    
    for(int i=1;i<argc;i++)
        arglist[i-1] = argv[i];
    arglist[argc-1]=NULL;

    execvp("daemon ejer", arglist);

}
