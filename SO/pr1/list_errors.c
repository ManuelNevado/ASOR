#include "cabeceras.h"

int main(){
    setuid(200);
    for (int i=1;i<256;i++){
        fprintf("%s\n",strerror(i));
    }
    return 0;
}
