#include "cabeceras.h"

int main(){
    int o = open("./test5",O_TRUNC | O_CREAT,0645);
    if(o)
        printf("Done!\n");
    else
        printf("Error\n");
    return 0;
}
