CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror 
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

CFILES = cola.c pruebas_alumno.c testing.c main.c
HFILES = cola.h testing.h
EXEC_S = pruebas

build: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) -o $(EXEC_S) $(CFILES)
	
run: build
	./$(EXEC_S)

valgrind: build
	valgrind $(VFLAGS) ./$(EXEC_S)

clean:
	rm -f *.o $(EXEC_S)
