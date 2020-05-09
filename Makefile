CC=gcc
SRC=main.c pgm.c draw.c
INCLUDE=.
BINARY=main
LIBRARIES=-lm


all:
	@$(CC) -o $(BINARY) $(SRC) -I$(INCLUDE) $(LIBRARIES)

run:
	@./$(BINARY)