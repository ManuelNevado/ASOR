/*
 * Escribir un programa que emule el comportamiento de la shell en la ejecución de una sentencia en la forma:
 * comando1 argumento1 | comando2 argumento2. El programa creará una tubería sin nombre y creará un hijo:

 El proceso padre redireccionará la salida estándar al extremo de escritura de la tubería y ejecutará comando1 argumento1.
El proceso hijo redireccionará la entrada estándar al extremo de lectura de la tubería y ejecutará comando2 argumento2.
Probar el funcionamiento con una sentencia similar a: ./ejercicio1 echo 12345 wc -c

 */
#include "cabeceras.h"

int main(int argc, char** argv){
    
    if(argc!=5){
        printf("Error en la entrada de argumentos\n");
        return 1;
    }

    char* line1[3] = {argv[1],argv[2],NULL};
    char* line2[3] = {argv[3], argv[4], NULL};

    //pipes
    //Se crea la tuberia sin nombre
    int fd[2];

    int paip = pipe(fd);

    //Se crean los procesos

    pid_t forked = fork();

    if(forked == -1){
        perror("Error en el fork(2)\n");
        return errno;
    }

    if(forked == 0){
        //Child
        close(fd[1]);
        dup2(fd[0],0);//Entrada estandar = 0
        close(fd[0]);
        execvp(argv[3],line2);

        
    }else{
        
        //Parent
        close(fd[0]);
        dup2(fd[1],1);//1=stdout en file_descript
        close(fd[1]);
        execvp(argv[1], line1);
        //Coger fallo de execvp
    }


    return 0;
}
