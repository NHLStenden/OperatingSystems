#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>


/**
 * Instructions
 *
 * Reads characters over a named pipe.
 *
 * First start the program writepipe.c. once the program connects with that pipe output is received
 *
 * Also try on a Linux prompt (once the pipe is created through the c-progam 'readpipe.c'
 * cat < /tmp/myfifo
 * cat < /tmp/myfifo | wc -c
 * cat < /tmp/myfifo > test.txt
 *
 */

/* File Descriptor for pipe */
int fd;

/** handler for CTRL+C for proper closing the pipe */
void intHandler(int dummy) {
    fprintf(stderr, "\nPressed control-c\n");

    close(fd);
    fprintf(stderr, "\nPipe closed\n");
    exit(0);
}// intHandler

int main()
{
    // install a proper signal handler
    signal(SIGINT, intHandler);

    // FIFO file path
    char *myfifo = "/tmp/myfifo";

    fprintf(stderr, "**** Opening pipe, waiting for other party to connect\n");
    fd = open(myfifo, O_RDONLY);

    fprintf(stderr, "**** Pipe opened. Waiting for characters from pipe.\n\n");

    // buffer for holding the incoming data
    char pipedata[256];
    // flag to stop while-loop on EOF on pipe
    int reachedEOFOnPipe = false;

    // counter of nr of bytes (useful for checking)
    int count = 0;

    while (!reachedEOFOnPipe)
    {
        // Read from FIFO
        ssize_t bytesRead;
        int bytesReadInt;
        bytesRead = read(fd, pipedata, sizeof(pipedata) - 2);

        bytesReadInt = (int) bytesRead;

        // check for EOF and set flag
        reachedEOFOnPipe = (bytesReadInt == 0);

        // make sure buffer is terminated (on buffer full, the \0 may not have reached our side of the pipeline
        pipedata[(int) bytesReadInt] = '\0';

        // increase counter
        count += (int) bytesRead;

        // if not EOF, then send to STDOUT
        if (!reachedEOFOnPipe) printf("%s", pipedata);
    }
    // some reporting afterwards
    fprintf(stderr, "Pipe reached EOF\n");
    fprintf(stderr, "Received: %d\n", count);

    // close the pipe
    close(fd);
    return 0;
}// main
