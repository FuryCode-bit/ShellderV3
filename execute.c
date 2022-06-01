#include "shell.h"

void execute(int numargs, char **args)
{
  int indice, NovopidFilho, fd[2];
  int pid, status;
  int code = ultimo(&numargs, args);
  if ((pid = fork()) < 0)
  {                  /* cria um processo progenito */
    perror("forks"); /* NOTE: perror() produz uma pequema mensagem de erro para o stream */
    exit(1);         /* estandardizado de erros que descreve o ultimo erro encontrado */
                     /* durante uma chamada ao sistema ou funcao duma biblioteca */
  }

  if (pid == 0)
  {
    indice = containsPipe(numargs, args);
    if (indice > 0)
    {
      args[indice] = NULL;
      pipe(fd);          // criar pipe
      NovopidFilho = fork(); // fork

      if (NovopidFilho == 0)
      {
        numargs = indice;
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]); // fd[0] -Input(leitura) fd[1]-output(escrita)
      }
      else
      {
        args = args + indice + 1;
        numargs = numargs - indice - 1;

        dup2(fd[0], STDIN_FILENO); // duplicar o descritor de ficheiro de leitura do PIPE para a posição na tabele de FD do STDIN
        close(fd[0]);              // fechar o descritor do ficheiro do pipe que este processo não necessita.
        close(fd[1]);
      }
    }

    numargs = redirects(numargs, args);
    if (numargs == -1)
    {
      exit(0); // fecha o filho
    }
    execvp(*args, args); /* NOTE: as versoes execv() e
                          * execvp() de execl() sao uteis quando */
    perror(*args);       /* o numero de argumentos nao e. conhecido.
                          * Os argumentos de  */
    exit(1);             /* execv() e execvp() sao o nome do ficheiro
                          * a ser executado e um */
  }                      /* vector de strings que contem os
                          * argumentos. O ultimo argument */
  if (FG == code)
  {
    while (wait(&status) != pid)
    {
    }
  }
  /*spin fazer nada */;

  return;
}

int ultimo(int *numargs, char **args)
{
  if (args[*numargs - 1][0] == '&')
  {
    *numargs = *numargs - 1;
    args[*numargs] = NULL;
    return BG;
  }
  return FG; /*return FG ou BG definidos no shell.h */
}