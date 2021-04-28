encoding:
	gcc -Wall -O3 -pedantic -Iinclude -std=c99 -o bin/encoding src/encoding.c

asm:
	gcc -Wall -O2 -pedantic -Iinclude -S -std=c99 -o src/encoding.S src/encoding.c

compile:
	gcc -c src/encoding.S -o bin/encoding.o && gcc bin/encoding.o -o bin/encoding
