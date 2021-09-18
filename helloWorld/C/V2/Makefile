#  https://www.gnu.org/software/make/manual/make.html

# Linking done through gcc -c https://gcc.gnu.org/onlinedocs/
helloworld : hello.o myfunctions.o
	gcc -o helloworld hello.o myfunctions.o

hello.o : hello.c
	gcc -c hello.c

myfunctions.o : myfunctions.c myfunctions.h
	gcc -c myfunctions.c

clean :
	rm helloworld myfunctions.o hello.o

