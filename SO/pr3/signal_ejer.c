/*
    Escribir un programa que bloquee las señales SIGINT y SIGTSTP.
    Después de bloquearlas el programa debe 
    suspender su ejecución con sleep(3)

 * SIGINT: Interrupción. Se puede generar con Ctrl+C (F)
 * SIGTSTP: Parar proceso. Se puede generar con Ctrl+Z (P)
 */

#include "cabeceras.h"
#define SLEEP_SECS 3

void sigs(){
    printf("\nsignal captured\n");
    sleep(SLEEP_SECS);
}

int main(int argc, char** argv){
    
    //Se bloquea la signal de Ctrl-c
    printf("Se bloquea el control+c\n");
   
    for(int i=0;i<1000000;i++){
        signal(SIGINT,sigs);
        printf("\rCount: %d",i);
        fflush(stdout);
    }
    printf("\n");
    


    printf("Ahora con control+z");
    for(int i=0;i<1000000;i++){
        signal(SIGTSTP,sigs);
        printf("\rCount: %d",i);
        fflush(stdout);
    }
    printf("\nDone!\n");

    return 0;
}
