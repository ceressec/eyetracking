CC = gcc
HEADER = include
CFLAGS = -c -Wall -O2 -pedantic -I$(HEADER)

encoding:
	$(CC) $(CFLAGS) -o bin/encoding src/encoding.c

clean: 
	rm -rf *o hello