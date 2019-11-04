SRC = items.c rooms.c adventure.c items.h rooms.h
OBJ = items.o rooms.o adventure.o
PROG = textadventure

$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)
