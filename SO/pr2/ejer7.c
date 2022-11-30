#include "cabeceras.h"

int main(){    
    umask(0727);
    open("./test7",O_CREAT | O_TRUNC);

    return 0;
}
