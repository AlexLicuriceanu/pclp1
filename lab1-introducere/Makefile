# Declaratiile de variabile
CC = gcc
CFLAGS = -Wall -lm
SRC = hello.c
EXE = hello
 
# Regula de compilare
all:
	$(CC) -o $(EXE) $(SRC) $(CFLAGS)
 
# Regulile de "curatenie" (se folosesc pentru stergerea fisierelor intermediare si/sau rezultate)
.PHONY : clean
clean :
	rm -f $(EXE) *~
