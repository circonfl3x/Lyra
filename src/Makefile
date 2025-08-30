test: clean
	gcc *.c -g -fsanitize=address -o lyra ; ./lyra

obj:
	gcc lyra.c -c lyra.o
objdev:
	gcc lyra.c -c lyra.o -g -fsanitize=addrexs
clean:
	rm -rf lyra
