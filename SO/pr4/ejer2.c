/*
 * Para la comunicación bi-direccional, es necesario crear dos tuberías, una para cada sentido: p_h y h_p. 
 * Escribir un programa que implemente el mecanismo de sincronización de parada y espera:
 * 
 * El padre leerá de la entrada estándar (terminal) y enviará el mensaje al proceso hijo, 
 * escribiéndolo en la tubería p_h. 
 * Entonces permanecerá bloqueado esperando la confirmación por parte del hijo en la otra tubería, h_p.
 * El hijo leerá de la tubería p_h, escribirá el mensaje por la salida estándar y esperará 1 segundo. 
 * Entonces, enviará el carácter ‘l’ al proceso padre, escribiéndolo en la tubería h_p, 
 * para indicar que está listo. 
 * Después de 10 mensajes enviará el carácter ‘q’ para indicar al padre que finalice.
 */

#include "cabeceras.h"
#define MAX_BUFF 200



int main(int argc, char** argv){

    //Prepare the pipes
    int p_h[2];
    int h_p[2];

    pipe(p_h);
    pipe(h_p);

    if(errno){
        perror("ERROR\n");
        return errno;
    }
    pid_t forked = fork();
    if(errno)
        return errno;//Error en fork

    if(forked == 0){
        //Child
        //Prepare the buffer to read and write    
        char buffer[MAX_BUFF];
        //line = getline(&buffer,&len, stdin);
        
        int i=0;
        while(i<5){
            //Escribir
            printf("Desde el hijo: Escribe lo que quieras enviar -> ");
            scanf("%s", buffer);
            //printf("Desde el padre se va a enviar: %s\n", buffer);
            write(h_p[1],buffer,MAX_BUFF);
            if (errno)
                raise_error();
            //Leer
            int size = read(p_h[0],buffer, MAX_BUFF);
            if(errno)
                raise_error();
            printf("Desde el hijo: Mensaje recibido -> %s\n",buffer);
            //i++
            i++;
        }
    }else{
        //Parent
        //Prepare the buffer to read and write    
        int i=0;
        while(i<5){
            char buffer[MAX_BUFF];
            
            //Lectura
            int size = read(h_p[0],buffer, MAX_BUFF);
            if(errno)
                raise_error();
            printf("Desde el padre: Mensaje recibido -> %s\n",buffer);
            //Escritura
            printf("Desde el padre: Escribe lo que quieras enviar -> ");
            scanf("%s",buffer);
            write(p_h[1],buffer,MAX_BUFF);
            if (errno)
                raise_error();
            i++;
        } 

     }
    return 0;
}

