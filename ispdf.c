#include "shell.h"

int ispdf(int fd){
    unsigned char b[4];
    read(fd, b, 4);
    
    if (b[0] == 0x25 && b[1] == 0x50 && b[2] == 0x44 && b[3] == 0x46){
        return 1;
    }
    return 0;
}