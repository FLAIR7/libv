CC = gcc
CFLAGS = -Wall -Wextra -Werror

build:
	$(CC) $(CFLAGS) ./src/*.c -lm -o libv 
