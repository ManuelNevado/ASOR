/*
 * Escribir un programa que instale un manejador para las señales SIGINT y SIGTSTP. 
 * El manejador debe contar las veces que ha recibido cada señal. 
 * El programa principal permanecerá en un bucle que se detendrá cuando se hayan recibido 10 señales. 
 * El número de señales de cada tipo se mostrará al finalizar el programa.
 */

#include "cabeceras.h"

int c = 0;
int z = 0;

void ctrl_c(){
    c+=1;
}

void ctrl_z(){
    z+=1;
}

int main(int argc, char** argv){
    printf("PID: %d\nEmpieza la cuenta\n", getpid());
    while(c<10 && z<10){
        signal(SIGINT, ctrl_c);
        signal(SIGTSTP, ctrl_z);
        printf("\rctrl-c: %d, ctrl-z: %d",c,z);
        fflush(stdout);
    }

    printf("\n");

    return 0;
}
