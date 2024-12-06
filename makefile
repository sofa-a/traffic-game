CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror
OBJ = checks.o game.o player.o cars.o arrays.o display.o \
terminal.o linked_list.o scene.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

checks.o : checks.c checks.h game.h arrays.h
	$(CC) -c checks.c $(CFLAGS)

game.o : game.c game.h display.h arrays.h linked_list.h scene.h cars.h player.h 
	$(CC) -c game.c $(CFLAGS)

scene.o : scene.c scene.h terminal.h linked_list.h
	$(CC) -c scene.c $(CFLAGS)

player.o : player.c player.h
	$(CC) -c player.c $(CFLAGS)

cars.o : cars.c arrays.h cars.h
	$(CC) -c cars.c $(CFLAGS)

display.o : display.c arrays.h display.h
	$(CC) -c display.c $(CFLAGS)

arrays.o : arrays.c arrays.h
	$(CC) -c arrays.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

linked_list.o : linked_list.c linked_list.h
	$(CC) -c linked_list.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
