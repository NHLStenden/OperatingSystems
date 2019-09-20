#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Instructions
 *
 * Run this program from a Linux command line and start entering characters; the lines are typically sent when newline is pressed.
 * Output is copied to STDOUT. Informational stuff is printed at STDERR
 *
 * other forms from the Linux command line:
 * 1) This one will check if the whole file is sent correctly by catching the output and running a DIFF-command with
 *    the original input.
 * $ ./writepipe < inputfile.txt > /tmp/result.out && diff inputfile.txt /tmp/result.out
 *
 * Once the pipe is created (in /tmp/mypipe) also the CAT-command line works:
 * $ cat > /tmp/myfifo
 *
 * Notice that the Pipe (/tmp/myfifo) needs to be disposed of through a Linux RM command from the command line (or a
 *   reboot as the file resides in /tmp)
 */

/** File descriptor for pipe */
int fd;

void intHandler(int dummy) {
    fprintf(stderr, "\nPressed control-c\n");

    close(fd);
    fprintf(stderr, "\nPipe closed\n");
    exit(0);
}

int main() {
    signal(SIGINT, intHandler);

    // FIFO file path
    char *myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO) --> only this side of the pipeline will create the file (not the reading part)
    mkfifo(myfifo, 0666);

    // some reporting to STDERR
    fprintf(stderr, "**** Opening pipe, waiting for other party to connect\n");

    // open the file
    fd = open(myfifo, O_WRONLY);

    // indicate the pipe has a sending and receiving end setup
    fprintf(stderr, "**** Pipe opened. Waiting for user input from keyboard\n\n");

    char reachedEOF = false;
    int count = 0;

    while (!reachedEOF) {
        // receive one char at a time
        char c;
        c = fgetc(stdin);

        // check for EOF
        reachedEOF = (c == EOF);

        // if not EOF on STDIN, send it through the pipe
        if (!reachedEOF) {
            count++;

            write(fd, &c, 1);

            // send a copy of the read char to STDOUT (--> this way we can check input and output using Linux DIFF-command
            fprintf(stdout, "%c", (int) c);
        }
    }
    fprintf(stderr, "\nReached EOF\nTerminating\n");
    fprintf(stderr, "Written : %d\n", count);
    close(fd);
    return 0;
}
