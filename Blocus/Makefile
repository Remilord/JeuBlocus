### VARIABLES ###
 
CC = gcc
CFLAGS = -Wall \
         -ansi \
         -pedantic \
         -lgraph
EXE = blokus
OFILES = menu.o \
         main.o \
         gameplay.o 
 
### BUT PAR DEFAUT ###
 
but : ${EXE}
 
### REGLES ESSENTIELLES ###
 
menu.o : menu.h

gameplay.o : gameplay.h menu.h
 
main.o : menu.h gameplay.h
 
${EXE} : ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES}
 
### REGLES OPTIONNELLES ###
 
clean :
	-rm -f ${OFILES}
 
mrproper : clean but
 
### BUTS FACTICES ###
 
.PHONY : but clean mrproper
 
### FIN ###