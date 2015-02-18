CC=gcc
CFLAGS=-Wall -Werror

.PHONY : clean


myShell : csapp.c csapp.h eval.c myshell.c myshell.h parseline.c jobs.c jobs.h
	 $(CC) $(CFLAGS) -o $@ $^ -lpthread -O0

clean :
	rm -fv myShell *.o *~*
