CC=gcc

DEBUG=-O0
RELEASE=-O2
CFLAGS=-std=c99 -Wall -Wextra

test:
	echo "Testing debug build..."
	${CC} bits.c bits_test.c -o bits_test ${CFLAGS} ${DEBUG}
	./bits_test

	echo "Starting release build..."
	${CC} bits.c bits_test.c -o bits_test ${CFLAGS} ${RELEASE}
	./bits_test

clean:
	rm -rf bits_test 2> /dev/null
