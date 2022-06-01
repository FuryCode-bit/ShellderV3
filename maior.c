#include "shell.h"

int FSize(FILE *file){
    int n = 0, ch;
    char *line = NULL;

    while ((ch = fgetc(file)) != EOF){
        line = (char *)realloc(line, sizeof(char) * (n + 2));
        line[n] = ch;
        n++;
    }
    return n;
}

//fazer a retornar int
void maior(char *fd1, char *fd2){
    FILE *f1, *f2;

    f1 = fopen(fd1, "rb");
    f2 = fopen(fd2, "rb");

    int s1 = FSize(f1)/1024;
    int s2 = FSize(f2)/1024;

    if(s1 > s2){
        printf("Maior . [%s] -> %dKB\n", fd1, s1);
    }else if(s1 < s2){
        printf("Maior . [%s] -> %dKB\n", fd2, s2);
    }else{
        printf("mesmo tamanho\n");
    }
}