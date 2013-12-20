all: glx-test.o link

glx-test.o: glx-test.c
	gcc -c -g -O0 glx-test.c

link: glx-test.o
	gcc glx-test.o -lGL -lX11 -o glx-test

clean: 
	rm glx-test.o glx-test
