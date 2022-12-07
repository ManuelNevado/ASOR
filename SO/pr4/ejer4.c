/*
 * Escribir un programa que abra la tubería con el nombre anterior en modo sólo escritura, y escriba en ella el primer argumento del programa. 
 * En otro terminal, leer de la tubería usando un comando adecuado.
 */

#include "cabeceras.h"
#define MAX_BUFFER 10 
int main(int argc, char** argv){
    
    
    int fd = open("./test",O_WRONLY );
    if(errno){
        raise_error();
        return errno;
    }
    write(fd, "test\n", 6);
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
