#! /bin/bash

app: main.o init.o mainMenu.o exitFunc.o openDev.o closeDev.o writeDev.o readDev.o lseekDev.o
	gcc -o app main.o init.o mainMenu.o exitFunc.o openDev.o closeDev.o writeDev.o readDev.o lseekDev.o

lseekDev.o: lseekDev.c headers.h declarations.h
	gcc -c lseekDev.c
readDev.o: readDev.c headers.h declarations.h
	gcc -c readDev.c
writeDev.o: writeDev.c headers.h declarations.h
	gcc -c writeDev.c
closeDev.o: closeDev.c headers.h declarations.h
	gcc -c closeDev.c
openDev.o: openDev.c headers.h declarations.h
	gcc -c openDev.c
exitFunc.o: exitFunc.c headers.h declarations.h
	gcc -c exitFunc.c
mainMenu.o: mainMenu.c headers.h declarations.h
	gcc -c mainMenu.c
init.o: init.c headers.h declarations.h
	gcc -c init.c
main.o: main.c headers.h declarations.h
	gcc -c main.c

clean: 
	rm *.o
