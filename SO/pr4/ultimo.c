/*
 * Crear otra tubería con nombre.
 * Escribir un programa que espere hasta que haya datos listos para leer en alguna de ellas. 
 * El programa debe mostrar la tubería desde la que leyó y los datos leídos. Consideraciones:
 *
 *      Para optimizar las operaciones de lectura usar un buffer (ej. de 256 bytes).
 *
 *      Usar read(2) para leer de la tubería y gestionar adecuadamente la longitud de los datos leídos.
 *
 *      Normalmente, la apertura de la tubería para lectura se bloqueará hasta que se abra para escritura.
 *
 *      Para evitarlo, usar la opción O_NONBLOCK en open(2).
 *
 *      Cuando el escritor termina y cierra la tubería, read(2) devolverá 0, indicando el fin de fichero, 
 *      por lo que hay que cerrar la tubería y volver a abrirla.
 *      Si no, select(2) considerará el descriptor siempre listo para lectura y no se bloqueará.
 */


#include "cabeceras.h"
#define STR_LENGTH 10
#define MAX_BUFFER 100

int main(int argc, char** argv){
    
    char name[STR_LENGTH] = "wfrgswety\0";

    mkfifo(name, 0777);
    if(errno){
        raise_error();
        return errno;
    }

    //Leer de la tuberia
    char buffer[MAX_BUFFER];
    int fd = open(name, O_RDONLY);
    int length;
    printf("Dispuesto a leer\n");
    length = read(fd,buffer,MAX_BUFFER);

    printf("%s\n", buffer);

    return 0;
}
