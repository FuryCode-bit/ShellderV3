#include "shell.h"

int isjpeg(int fd){
    unsigned char b[4];
    read(fd, b, 4);

    lseek(fd, SEEK_SET, 0);
    if(b[0] == 0xff && b[1] == 0xd8 && b[2] == 0xff && b[3] == 0xe0){
        return 1;
    }
    return 0;
}