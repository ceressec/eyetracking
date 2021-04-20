encoding:
	gcc -O2 -o bin/encoding src/encoding.c

test:
	gcc -o bin/test test/test_encoding.c