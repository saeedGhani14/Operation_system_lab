all: 

static: st_static.o libstatic.a 
	gcc main.c -L./ -lstatic -o main

libstatic.a: st_static.o
	ar -r libstatic.a st_static.o

st_static.o:
	gcc -c static.c -o st_static.o

st_clean:
	rm -rf main.o static.o main libstatic.a

dynamic: dystatic.o libdystatic.so
	gcc main.c -L./ -ldystatic -o main

libdystatic.so: dystatic.o
	gcc -shared dystatic.o -o libdystatic.so
dystatic.o:
	gcc -c -fPIC static.c -o dystatic.o
dy_clean:
	rm -rf main dystatic.o libdystatic.so

main: static.o main.o
	gcc -c static.o main.o -o main
static.o:
	gcc -c static.c -o static.o
main.o:
	gcc -c main.c -o main.o
clean:
	rm -rf main.o main static.o

install:
	sudo mv main /usr/local/bin/main
	sudo install -m 755 main /usr/local/bin/

uninstall:
	rm -rf /usr/local/bin/main

