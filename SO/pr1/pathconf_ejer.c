#include "cabeceras.h"

int main(){
    long int arg_max = pathconf(".",_PC_LINK_MAX);
    long int child_max = pathconf(".",_PC_PATH_MAX);
    long int file_max = pathconf(".",_PC_NAME_MAX);
    printf("LINK: %ld\n",arg_max);
    printf(" PATH: %ld\n",child_max);
    printf(" NAME: %ld\n",file_max);

    return 0;
}
