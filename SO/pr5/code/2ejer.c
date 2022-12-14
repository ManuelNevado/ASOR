/*
 * Escribir un servidor UDP de hora de forma que:
La dirección y el puerto son el primer y segundo argumento del programa. Las direcciones pueden expresarse en cualquier formato (nombre de host, notación de punto…). Además, el servidor debe funcionar con direcciones IPv4 e IPv6 .
El servidor recibirá un comando (codificado en un carácter), de forma que ‘t’ devuelva la hora, ‘d’ devuelve la fecha y ‘q’ termina el proceso servidor.
En cada mensaje el servidor debe imprimir el nombre y puerto del cliente, usar getnameinfo(3).
Probar el funcionamiento del servidor con la herramienta Netcat (comando nc o ncat) como cliente.
Nota: Dado que el servidor puede funcionar con direcciones IPv4 e IPv6, hay que usar struct sockaddr_storage para acomodar cualquiera de ellas, por ejemplo, en recvfrom(2).
Ejemplo:

 */



#include "cabeceras.h"
#define MAX_BUF 500

char* tratamiento(char *buf);
void server(int argc, char** argv);
void cliente(int argc, char** argv);

int main(int argc, char** argv){

    if(argc != 3){
        printf("Formato de ejecucion erroneo\nEl formato debe ser:\n\t%s [host] [puerto]\n", argv[0]);
        return 1;
    }

    int forked = fork();

    if(!forked){
        //padre 
        //Se ejecuta el codigo del server
        server(argc, argv);
    }else{
        //Hijo
        //Se ejecuta el codigo del cliente
        cliente(argc, argv);
    }

    return 0;
}

void server(int argc, char** argv){
    //Se crean las variables necesarias
    struct sockaddr_un server_address, client_address;
    socklen_t cient_address_size;
    
    //se crea el servidor
    int upd_sd = socket(AF_INET, SOCK_DGRAM, 0);
    if(errno){
        raise_error("Error creando el socket");
        return;
    }

    //Se rellena con 0 el struct server_address
    memset(&server_address, 0, sizeof(server_address));
    //Se enmascaran los campos que queremos
    server_addres.sun_family = AF_INET;//AF_INET == protocolo UDP
    
    //Se hace el bind
    bind(upd_sd, (struct sockaddr *)&server_address, sizeof(server_address));
    if(errno){
        raise_error("Error en el bind");
        return;
    }

    //recvfrom loop
    while(1){
        ssize_t nread;
        char buf[MAX_BUF];
        nread = recvfrom(udp_sd, buf, MAX_BUF, 0, (struct sockaddr *) &client_address, sizeof(client_address));
        if(errno){
            raise_error("Error leyendo datos");
            return;
        }
        char host[NI_MAXHOST], service[NI_MAXSERV];
        int s = getnameinfo((struct sockaddr *) &client_address, sizeof(client_address),
                host, NI_MAXHOST, service, NI_MAXHOST, NI_NUMERICSERV);
        if(s==0)
            printf("SERVER: Rcibidos %zd bytes desde %s:%s\n", nread, host, service);
        else
            fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));

        //Tratamiento de la respuesta
        char answer[MAX_BUF] = tratamiento(buf);
        //Se envia la informacion al cliente
        sendto(udp_sd, answer, nread, 0, (struct sockaddr *) &client_address, sizeof(client_address));
        if(errno){
            raise_error("Error enviando paquete");
            return;
        }
    }

}

void cliente(int argc, char** argv){
    

}

char* tratamiento(char* buf){
    char q = 'q';
    char d = 'd';
    char t = 't';
    if(buf[0] == q)
        return q;
    else if(buf[0] == d)
        //TODO hora del sistema
    else if(buf[0] == t)
        //TODO fecha del sistema
    return {'c','a','c','a', '\0'};
}
