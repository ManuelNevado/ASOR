/*
    Escribir un programa que bloquee las señales SIGINT y SIGTSTP.
    Después de bloquearlas el programa debe 
    suspender su ejecución con sleep(3)
 */
/*
 * SIGINT: Interrupción. Se puede generar con Ctrl+C (F)
 * SIGTSTP: Parar proceso. Se puede generar con Ctrl+Z (P)
 */

#include "cabeceras.h"

int main(int argc, char** argv){

    sigset_t* set = (sigset_t*) malloc(sizeof(sigset_t*2));


    if(sigprocmask(SIG_BLOCK, set, NULL)){
        int i=0;
        while(1){
            printf("\rCount: %d",i);
            fflush(stdout);
            i++;
        }
    } 
    
    return 0;
}
