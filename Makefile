FLAGS=-c -Wall
LIBS=-lm
OBS=main.o execute.o parse.o calculadora.o redirects.o aviso.o socd.o isjpeg.o ispdf.o pipe.o maior.o setPerms.o sols.o socp.o -lpthread

#Alvo por defeito é o primeiro
all :  soshell

main.o : shell.h main.c
	gcc $(FLAGS) main.c
execute.o : shell.h execute.c
	gcc $(FLAGS) execute.c
parse.o : shell.h parse.c
	gcc $(FLAGS) parse.c
calculadora.o : shell.h calculadora.c 
	gcc $(FLAGS) calculadora.c
redirects.o : shell.h redirects.c
	gcc $(FLAGS) redirects.c
aviso.o : shell.h aviso.c
	gcc $(FLAGS) aviso.c
socd.o : shell.h socd.c
	gcc $(FLAGS) socd.c
isjpeg.o : shell.h isjpeg.c
	gcc $(FLAGS) isjpeg.c
ispdf.o : shell.h ispdf.c
	gcc $(FLAGS) ispdf.c
pipe.o : shell.h pipe.c
	gcc $(FLAGS) pipe.c
maior.o : shell.h maior.c
	gcc $(FLAGS) maior.c
setPerms.o : shell.h setPerms.c
	gcc $(FLAGS) setPerms.c
sols.o : shell.h sols.c
	gcc $(FLAGS) sols.c
socp.o : shell.h socp.c
	gcc $(FLAGS) socp.c
soshell : $(OBS)
	gcc  -o soshell  $(OBS) $(LIBS)
clean limpar:
	rm -f *.o
	rm -f *~
	echo "Clean"
