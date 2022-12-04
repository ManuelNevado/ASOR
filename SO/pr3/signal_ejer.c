/*
    Escribir un programa que bloquee las señales SIGINT y SIGTSTP.
    Después de bloquearlas el programa debe 
    suspender su ejecución con sleep(3)

 * SIGINT: Interrupción. Se puede generar con Ctrl+C (F)
 * SIGTSTP: Parar proceso. Se puede generar con Ctrl+Z (P)
 */

#include "cabeceras.h"
#define SLEEP_SECS 3
int main(int argc, char** argv){
    
    //Se bloquea la signal de Ctrl-c
    printf("Se bloquea el control+c\n");
    __sighandler_t s = signal(SIGINT, SIG_IGN); 
    for(int i=0;i<1000000;i++){
        printf("\rCount: %d",i);
        fflush(stdout);
    }
    printf("\n");
    
    if(*s == SIGINT){
        printf("\n\nCtrl-c detectado\n");
        sleep(SLEEP_SECS);
    }

    if(SIG_ERR)
        printf("SIG_ERR raised: %d\n", SIG_ERR);

    printf("Ahora con control+z");
    s = signal(SIGTSTP, SIG_IGN);
    for(int i=0;i<1000000;i++){
        printf("\rCount: %d",i);
        fflush(stdout);
    }
    printf("\nDone!\n");

    if(*s == SIGTSTP){
        printf("\n\nCtrl-c detectado\n");
        sleep(SLEEP_SECS);
    }
    if(SIG_ERR)
        printf("SIG_ERR raised: %d\n", SIG_ERR);

    return 0;
}
