#include "shell.h"

char prompt[100];

int main ()
{
  int len;
  char linha[1024];/* um comando */
  char *args[64];/* com um maximo de 64 argumentos */

  strcpy (prompt, "SOSHELL>");
  while (1)
  {
    printf ("%s", prompt);
    if (fgets (linha, 1023, stdin) == NULL)
    {
      printf ("\n");
      exit (0);
    }
    len = strlen (linha);
    if (1 == len)
      continue;/* linha é apenas \n */
    if (linha[len - 1] == '\n')
      linha[len - 1] = '\0';
    int numargs = parse(linha, args);/* particiona a string em argumentos */

    if (!builtin (args))
      execute (numargs, args);/* executa o comando */
    }
  return 0;
}

int builtin (char **args)
{
  //usado para sair da shell
  if (strcmp (args[0], "exit") == 0)
  {
    exit (0);
    return 1;
  }

  //usado para indicar a versão atual da shell
  if (strcmp(args[0], "info") == 0)
  {
    printf("SoShellder 2020 versão 3.0\n");
    return 1;
  }

  if (strlen(args[0])>4 && strncmp(args[0], "PS1=", 4) == 0)
  {
    strcpy(prompt, args[0]+4);
    return 1;
  }

  //usado para mostrar informações sobre o utilizador
  if (strcmp(args[0], "id") == 0)
  {
    system("id");
    return 1;
  }

  //usado para se movimentar entre diretorias
  if (strcmp(args[0], "socd") == 0)
  {
    socd(args[1]);
    return 1;
  }

  //usado para fazer calculos matematicos simples
  if (strcmp(args[0], "calcula") == 0){
    calculadora(args[1], args[2], args[3]);
    return 1;
  }

  //usado para efetuar calculos binarios
  if (strcmp(args[0], "calculaBits") == 0){
    calculaBits(args[1], args[2], args[3]);
    return 1;
  }
  
  //usado para verificar se um ficheiro é um jpeg
  if (strcmp(args[0], "isjpeg") == 0)
  {
    if(isjpeg(open(args[1], O_RDONLY)) == 1)
      printf("YES\n");
    else
        printf("NO\n");

    return 1;
    }

    //usado para verificar se um ficheiro é um pdf
  if (strcmp(args[0], "ispdf") == 0)
  {
    if(ispdf(open(args[1], O_RDONLY)) == 1)
      printf("YES\n");
    else
        printf("NO\n");

    return 1;
    }
  
  //usado para mostrar um aviso dado um n tempo com threads
  if (strcmp(args[0], "aviso") == 0)
  {
    pthread_t th;
    aviso_t * ptr = (aviso_t *)malloc(sizeof(aviso_t));
    strcpy(ptr->msg, args[1]);
    ptr->tempo = atoi(args[2]);
    pthread_create(&th, NULL, timeAviso, (void *)ptr);
    return 1;
  }

  //usado para verificar qual o maior de dois ficheiros
  if(strcmp(args[0], "maior") == 0){
    maior(args[1], args[2]);
    return 1;
  }

  //Torna um ficheiro executavel
  if(strcmp(args[0], "setPerms") == 0){
    setPerms(args[1]);
    return 1;
  }

  //usado para remover a leitura de um ficheiro
  if(strcmp(args[0], "rmPerms") == 0){
    rmPerms(args[1]);
    return 1;
  }

  //usado para copiar um ficheiro para outro com threads
  if (strcmp(args[0], "socpth") == 0){
    pthread_t th;
    copiar_t *ptr = (copiar_t *)malloc(sizeof(copiar_t));
    strcpy(ptr->fonte, args[1]);
    strcpy(ptr->destino, args[2]);
    pthread_create(&th, NULL, socpwrapper, (void *)ptr);
    return 1;
  }

  //usado para copiar um ficheiro para outro sem threads
  if(strcmp(args[0], "socp") == 0){
    socp(args[1], args[2]);
    return 1;
  }

  //Implementação da função builtin (sols) – Uma Listagem Rápida
  if(strcmp(args[0], "sols") == 0){
    lista(".");
    return 1;
  }

  return 0;
}
