#include "cabeceras.h"

int main(int argc, char** argv){
    
    if(argc < 2){
        printf("Low number of arguments\n");
        printf("The executable must be followed by the command you want to execute\n");
        return 1;
    }

    //aqui lo que hago es dejar claro que el nombre no lo quiero pero esque en la ultima posicion
    //tengo que poner el NULL
    char* arglist[argc-1+1];

    for(int i=1;i<argc;i++)
        arglist[i-1] = argv[i];

    arglist[argc-1]=NULL;

    execvp(argv[1],arglist);

    if(errno){
        printf("An errno has been raised\n");
        perror(errno);
        return errno;
    }else
        printf("Comando ejecutado\n");

    return 0;
}


