#include "cabeceras.h"

int main(){
    long int arg_max = sysconf(_SC_ARG_MAX);
    long int child_max = sysconf(_SC_CHILD_MAX);
    long int file_max = sysconf(_SC_OPEN_MAX);
    printf("%ld\n",arg_max);
    printf("%ld\n",child_max);
    printf("%ld\n",file_max);

    return 0;
}
