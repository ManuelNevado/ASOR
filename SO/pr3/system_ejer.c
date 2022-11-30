#include "cabeceras.h"

int main(int argc, char** argv){
    if (argc != 2 ){
        fprintf(stderr,"Invalid number of arguments\n");
        return 1;
    }else{
        system(argv[1]);
        printf("El comando termino de ejecutarse\n");
    }
    return 0;
}
