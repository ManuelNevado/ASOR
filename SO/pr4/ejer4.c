/*
 * Escribir un programa que abra la tubería con el nombre anterior en modo sólo escritura, y escriba en ella el primer argumento del programa. 
 * En otro terminal, leer de la tubería usando un comando adecuado.
 */

#include "cabeceras.h"
#define MAX_BUFFER 100
int main(int argc, char** argv){
    
    if(argc!=2){
        printf("Error en el numero de argumentos\n");
        return 1;
    }    
    
    int fd = open("./test.txt",O_WRONLY);
    if(errno){
        raise_error();
        return errno;
    }
    write(fd, argv, MAX_BUFFER);
    if(errno){
        raise_error();
        return errno;
    }
    close(fd);
    if(errno){
        raise_error();
        return errno;
    }
    return 0;
}
