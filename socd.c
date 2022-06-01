#include "shell.h"
 
void socd(char *dir) {
    int err;
    if(NULL == dir || strcmp(dir, "~") == 0){
      err = chdir(getenv("HOME"));
    }else{
      err = chdir(dir);
    }
    if (err<0)
    {
      perror(dir);
    }
}