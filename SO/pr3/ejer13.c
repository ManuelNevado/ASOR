/*
 Escribir un programa que realice el borrado programado del propio ejecutable. 
 El programa tendrá como argumento el número de segundos que esperará antes de borrar el fichero. 
 El borrado del fichero se podrá detener si se recibe la señal SIGUSR1.
 */

#include "cabeceras.h"

void sombrerero(){
    kill(getpid(), SIGUSR1);
    printf("Se ha salvado al programa");
}

int main(int argc, char** argv){
    char* command[3] = {"rm", argv[0],NULL};
    long t = strtol(argv[1], NULL, 10);
    
    pid_t guillotina = getpid();
    printf("PID: %d\n",getpid());    
    pid_t forked = fork();
    
    if(forked ==-1){
        perror("Error en fork\n");
        return 1;
    }else if(forked != 0){
       signal(SIGINT,sombrerero);
    }else{
        printf("PID: %d\n",getpid());
        sleep(t);
        execvp("RM", command);
    }

    return 0;
}
