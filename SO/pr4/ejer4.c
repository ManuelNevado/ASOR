/*
 * Escribir un programa que abra la tubería con el nombre anterior en modo sólo escritura, y escriba en ella el primer argumento del programa. 
 * En otro terminal, leer de la tubería usando un comando adecuado.
 */

#include "cabeceras.h"
#define MAX_BUFFER 100
int main(int argc, char** argv){
    
    if(argc!=3){
        printf("Error en el numero de argumentos\n");
        printf("El formato de entrada debe ser palabra length, donde length es la longitud de la palabra\n");
        return 1;
    }    
    
    int fd = open("./test.txt",O_WRONLY);
    if(errno){
        raise_error();
        return errno;
    }
    write(fd, argv, atoi(argv[3]));
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
