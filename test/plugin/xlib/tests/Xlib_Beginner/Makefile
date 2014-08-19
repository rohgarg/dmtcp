all: Xlib_Beginner.o link

Xlib_Beginner.o: Xlib_Beginner.c
	gcc -c -g -O0 Xlib_Beginner.c -I/usr/X11R6/include

link: Xlib_Beginner.o
	gcc Xlib_Beginner.o -lX11 -o Xlib_Beginner

clean:
	rm Xlib_Beginner.o Xlib_Beginner
