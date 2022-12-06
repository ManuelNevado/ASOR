#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>

/*
int content_equals(char s1[], char s2[]){ //s1 y s2 deben ser cadenas terminadas en NULL
    //Esta funcion comprueba dos cadenas elemento a elemento hasta que una de ellas
    //llega a su componente null, en ese caso retorna 1 si son iguales y 0 si no
    int i =0;
    while(s1[i] != NULL && s2[i] != NULL){
        if(s1[i] != s2[i])
            return 0; //Las cadenas no son iguales
        else
            i++;
    }
    
    if(s1[i] == NULL && s2[i] == NULL)
        return 1; //Las cadenas son iguales -> Se devuelve True
    else
        return 0; //Una de las cadenas ha termindo antes que la otra asi que no son iguales -> Se devuelve False
}
*/

void raise_error(){
    printf("~~~~~~~~~~~~~\n");
    perror("");
    printf("~~~~~~~~~~~~~\n");
}
