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
#define MAX_BUFFER 256
#define MAX_TIME 3

int return_errno();
int info_source();

int main(int argc, char** argv){

    //Se crea el buffer
    char* buffer = (char*) malloc(256*sizeof(char));


    //Se crea la tuberia con nombre
    mkfifo("test_fifo", 0666);
    int fd_fifo = open("test_fifo", O_ASYNC);
    if(errno)
        return return_errno();

    //Se crea el set de File Descriptors
    fd_set file_descriptors;
    FD_ZERO(&file_descriptors);
    FD_SET(0,&file_descriptors);
    //FD_SET(1,&file_descriptors);
    FD_SET(fd_fifo,&file_descriptors);

    //Se crea el struct de tiempo
    struct timeval timeout;
    timeout.tv_sec = MAX_TIME;
    timeout.tv_usec = 0;

    //Select
    int cambios;
    
    int source = 0;

    while(1){
        cambios = select(source+1, &file_descriptors, NULL, NULL, &timeout);

        if (cambios == -1)
            return return_errno();
        else if(cambios){
            read(0,buffer,256);
            printf("Datos nuevos: %s\n", buffer);
        }else
           printf("Ningun dato nuevo en %d segundos\n",MAX_TIME);
        
        source = info_source(fd_fifo);

        sleep(3);
        
    }
    free(buffer);

    return 0;
}

int info_source(int fd){
    printf("0- stdin\n");
    printf("%d- fifo_pipe\n", fd);
    int source;
    scanf("%d", &source);
    return source;
}

int return_errno(){
    printf("~~~~~~~~~~~~~~~~~\n");
    perror("ERRNO RAISED\n");
    printf("~~~~~~~~~~~~~~~~~\n");
    return errno;
}
