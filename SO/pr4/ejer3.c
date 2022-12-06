/*
 *
 * Usar la orden mkfifo para crear una tubería con nombre. Usar las herramientas del sistema de ficheros (stat, ls…) para determinar sus propiedades. 
 * Comprobar su funcionamiento usando utilidades para escribir y leer de ficheros (ej. echo, cat, tee...).
 */

#include "cabeceras.h"


int main(int argc, char** argv){
    
    if(!mkfifo("./test.txt",0666))
        printf("Archivo creado\n");
    else
        raise_error();

    return 0;
}
