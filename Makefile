CC = gcc
FLAGS = -D BUFFER_SIZE=1
SOURCE = main.c get_next_line.c get_next_line_utils.c get_next_line.h

all:
	$(CC) $(FLAGS) $(SOURCE)

