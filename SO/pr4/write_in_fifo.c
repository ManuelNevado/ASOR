/*
 * Esto es un programa que me he creado para debuguear algunos ejercicios y escribir por la
 * tuberia con nombre
 * El programa escribe el dato que le metas por parametro en la tuberia fifo
 * con nombre que entra por parametro
 */

#include "cabeceras.h"

int main(int argc, char** argv){

    if(argc!=2){
        printf("Execution format invalid\nThe format should be:\n\t./[program] [pipe_name]\n");
        return 1;
    }
    
    printf("Abriendo la tuberia %s\n",argv[1]);
    int fd = open(argv[1], O_NONBLOCK);
    if(errno){
        perror("Error abriendo el pipe\n");
        return errno;
    }
    
    write(fd, "test\0", 5);
    if(errno){
        perror("Error escribiendo en el pipe\n");
        return errno;
    }

    close(fd);
    return 0;
}
