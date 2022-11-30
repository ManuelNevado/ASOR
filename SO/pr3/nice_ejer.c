#include "cabeceras.h"

int main(int argc, char* args[]){
    int nn = nice(0);    
    if(errno){
        fprintf(stderr, "Errno raised\n");
        return errno;
    }
    printf("Nice setted as %d\n", nn);
    
    return 0;
}
