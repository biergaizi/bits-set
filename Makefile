CFLAGS=-std=c99 -Wall -Wextra

test:
	gcc bits.c bits_test.c -o bits_test ${CFLAGS}
	bash -c 'echo "Start Testing"; ./bits_test'
clean:
	rm -rf bits_test 2> /dev/null
