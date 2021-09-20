#  https://www.gnu.org/software/make/manual/make.html

# Linking done through gcc -c https://gcc.gnu.org/onlinedocs/
helloworld : hello.o myfunctions.o
	gcc -o helloworld hello.o libmyfunctions.so

hello.o : hello.c libmyfunctions.so
	gcc -c hello.c
	gcc hello.o libmyfunctions.so

myfunctions.o : myfunctions.c myfunctions.h
	gcc -c myfunctions.c

libmyfunctions.so:
	gcc -shared -fPIC -o libmyfunctions.so myfunctions.c

clean :
	rm helloworld myfunctions.o hello.o libmyfunctions.so

