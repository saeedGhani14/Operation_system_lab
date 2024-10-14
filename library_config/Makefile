CC=gcc
perfix=/usr/local/bin/
app=main
AR=ar
path=./

all: 

#Static library
static: StaticMylib.o libStaticMylib.a 
	$(CC) main.c -L$(path) -lStaticMylib -o $(app)

libStaticMylib.a: StaticMylib.o
	$(AR) -r libStaticMylib.a StaticMylib.o

StaticMylib.o:
	$(CC) -c mylib.c -o StaticMylib.o

static_clean:
	rm -rf main.o StaticMylib.o main libStaticMylib.a



# Dynamic library
dynamic: libDyMylib.so
	$(CC) main.c -L$(path) -lDyMylib -o $(app)

libDyMylib.so: dyMylib.o
	$(CC) -shared dyMylib.o -o libDyMylib.so

dyMylib.o:
	$(CC) -c -fPIC mylib.c -o dyMylib.o

dynamic_clean:
	rm -rf $(app) dyMylib.o libDyMylib.so

#regular make 
main: mylib.o main.o
	$(CC) -c mylib.o main.o -o $(app)
mylib.o:
	$(CC) -c mylib.c -o mylib.o
main.o:
	$(CC) -c main.c -o main.o
clean:
	rm -rf main.o main mylib.o
install:
	sudo mv $(app) $(perfix)
	# sudo install -m 755 $(perfix) $(app)
uninstall:
	rm -rf $(perfix)

