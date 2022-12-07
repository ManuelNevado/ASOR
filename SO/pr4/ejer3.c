/*
 *
 * Usar la orden mkfifo para crear una tubería con nombre. Usar las herramientas del sistema de ficheros (stat, ls…) para determinar sus propiedades. 
 * Comprobar su funcionamiento usando utilidades para escribir y leer de ficheros (ej. echo, cat, tee...).
 */

#include "cabeceras.h"


int main(int argc, char** argv){
    
    if(argc != 2){
        printf("Error en el numero de argumentos\n");
        return 1;
    }

    char* line[3] = {"mkfifo", argv[1],NULL};
    execvp("mkfifo", line);

    return 0;
}
