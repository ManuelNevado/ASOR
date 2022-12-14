/* Escribir un programa que obtenga todas las posibles direcciones con las que se podría crear 
 * un socket asociado a un host dado como primer argumento del programa. 
 * Para cada dirección, mostrar la IP numérica, la familia de protocolos y tipo de socket.
 * 
 */

#include "cabeceras.h"
#define BUF_SIZE NI_MAXHOST

void cliente();
void servidor();

int main(int argc, char** argv){

           struct addrinfo hints;
           struct addrinfo *result, *rp;
           int sfd, s;
           size_t len;
           ssize_t nread;
           char buf[BUF_SIZE];

           if (argc < 2) {
               fprintf(stderr, "Usage: %s [host]\n", argv[0]);
               exit(EXIT_FAILURE);
           }

           /* Obtain address(es) matching host/port */

           memset(&hints, 0, sizeof(hints));
           hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
           hints.ai_socktype = 0; /* Datagram socket */
           hints.ai_flags = 0;
           hints.ai_protocol = 0;          /* Any protocol */

           s = getaddrinfo(argv[1], argv[2], &hints, &result);
           if (s != 0) {
               fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
               exit(EXIT_FAILURE);
            }
           for(rp = result; rp!=NULL; rp = rp->ai_next){
                char *host = (char*) malloc(BUF_SIZE*sizeof(char));
                getnameinfo(rp->ai_addr,rp->ai_addrlen,host,BUF_SIZE,NULL,0,NI_NUMERICHOST);
                printf("IP: %s\n",host);
                printf("Familia de protocolos: %d\n",rp->ai_family);
                printf("Tipo de Socket: %d\n", rp->ai_socktype);
                free(host);
           }
    return 0;
}

/*
void cliente(){
    
}

void servidor(){

}
*/
