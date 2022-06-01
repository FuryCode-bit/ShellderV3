#include "shell.h"
#include <math.h>

void calculadora(char *val1, char *val2, char *op){
    double x = atof(val1);
    double y = atof(val2);

    if(*op == '+'){
        printf("%.2f\n", x+y);
    }

    if(*op == '-'){
        printf("%.2f\n", x-y);
    }

    if(*op == '*'){
        printf("%.2f\n", x*y);
    }

    if(*op == '/' || *op == '%'){
        if(y == 0){
            printf("Erro, ao executar a operação\n");
        }else{
            printf("%.2f\n", x/y);
        }  
    }

    if(*op == '^'){
        printf("%.2f\n", powf(x,y));
    }
    if(*op != '/' && *op != '*' && *op != '-' && *op != '+' && *op != '^' && *op != '%'){
        printf("Erro, ao executar a operação\n");
    }
}

void calculaBits(char *val1, char *val2, char *op){
    int x = atoi(val1);
    int y = atoi(val2);
    if(*op == '&'){
        printf("%d\n", x&y);
    }
    if(*op == '|'){
        printf("%d\n", x|y);
    }
    if(*op == '^'){
        printf("%d\n", x^y);
    }
    if(*op != '^' && *op != '|' && *op != '&'){
        printf("Erro, ao executar a operação\n");
    }
}

