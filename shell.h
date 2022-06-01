#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <dirent.h>

void execute(int numargs, char **args);

int builtin (char **args);

int containsPipe(int numArgs, char** args);

typedef struct
{
    char msg[100]; 
    int tempo;
} aviso_t;

typedef struct
{
    char fonte[100];
    char destino[100];
} copiar_t;

#define BG 0
#define FG 1

void * timeAviso();
void * socpwrapper(void *args);
void calculadora();
void calculaBits();
void maior();
void socd();
int wait();
int redirects();
int prop();
int isjpeg();
int ispdf();
int rmPerms();
int setPerms();
int socp();
int ultimo();
int parse();
void lista();