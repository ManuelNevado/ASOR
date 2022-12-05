/*
 * Escribir un programa que emule el comportamiento de la shell en la ejecución de una sentencia en la forma:
 * comando1 argumento1 | comando2 argumento2. El programa creará una tubería sin nombre y creará un hijo:

 El proceso padre redireccionará la salida estándar al extremo de escritura de la tubería y ejecutará comando1 argumento1.
El proceso hijo redireccionará la entrada estándar al extremo de lectura de la tubería y ejecutará comando2 argumento2.
Probar el funcionamiento con una sentencia similar a: ./ejercicio1 echo 12345 wc -c

 */
#include "cabeceras.h"

int main(int argc, char** argv){
    
    //pipe(

    if(errno){
        perror("Error en el pipe\n");
        return errno;
    }


    return 0;
}
