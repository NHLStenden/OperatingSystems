#  https://www.gnu.org/software/make/manual/make.html
# procedure described in https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html

# Linking done through gcc -c https://gcc.gnu.org/onlinedocs/


# Step 1: indicate that the target 'helloworld' (= executable) depends on hello.o and libmyfunctions.o
# if these dependencies cannot be fulfilled yet, then run a compile statement.
# notice the option -l: this assumes the file begins with lib and ends with .so.
helloworld : hello.o libmyfunctions.so
        gcc -L${PWD} -o helloworld hello.o -lmyfunctions

# Step 2: indicate that hello.o depends on the hello.c and the library libmyfunctions.so
#  if not present, compile them
hello.o : hello.c libmyfunctions.so
        gcc -c hello.c

# Create the .so-file from the .o file
# option -fPIC => Position Independent Code
# option -o => designate output file
libmyfunctions.so:
        gcc -c -fPIC libmyfunctions.c
        gcc -shared -o libmyfunctions.so libmyfunctions.o

clean :
        rm helloworld libmyfunctions.o hello.o libmyfunctions.so
