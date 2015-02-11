CC=gcc
CFLAGS=-Wall -Werror

.PHONY : clean


myShell : csapp.c csapp.h eval.c myshell.c myshell.h parseline.c
	 $(CC) $(CFLAGS) -o $@ $^ -lpthread -O0

clean :
	rm -fv myShell *.o *~*
