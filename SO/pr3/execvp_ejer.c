#include "cabeceras.h"

int main(int argc, char** argv){
    
    execvp(argv[1], argv[2]);
    
    if(errno){
        perror(errno);
        return errno;
    }else
        printf("Comando ejecutado\n");

    return 0;
}


