#define _GNU_SOURCE 3
#include "cabeceras.h"


int main(){
    struct utsname *buf = (struct utsname *) malloc(sizeof(struct utsname));
    uname(buf);
    printf("%s\n",buf->sysname);
    printf(buf->nodename);
    printf(buf->release);
    printf(buf->version);
    printf(buf->machine);
    printf(buf->domainname);
    free(buf);
    return 0;
}

