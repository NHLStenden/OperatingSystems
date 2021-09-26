/*
* @author Martin Molema
* @organisation NHL Stenden
* @version 1
* @date 2021-09-26
* @seealso https://man7.org/linux/man-pages/man1/tee.1.html
* @description this program serves as an example for I/O redirection and the use
*   of getopts to change the behaviour of a CLI-program.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define true 1
#define false 0

int main(int argc, char **argv) {

  FILE *fp;
  
  opterr = 0;
  int useAppend = false;
  char c;
  
  /* Now start processing the options supplied on the command line.
  *  In this case only the -a option is used to change behaviour from 
  *  creating/overwriting the output file to appending to it .
  *  The -? option will print a usage message to stderr.
  */
  while ((c = getopt (argc, argv, "a")) != -1){
    switch (c)
      {
      case 'a':
        useAppend = true;
        fprintf (stderr,"using append-mode\n");
        break;
      case '?':
        /* information is sent to STDERR instead of STDOUT! to separate output
        *  from the real output 
        */
        fprintf (stderr,"usage: tee [-a] filename\n");
        fprintf (stderr,"  -a\tuse append instead of overwrite \n");
        return 1;
      default:
        abort ();
      }

  }

  /* now the variable 'optind' contains the next parameter to process
  *  if there are more parameters left (argc is the number of parameters 
  *  specified on the command line), then use the next as the filename.
  */
  char *filename;
  if (argc > optind){
    filename = argv[optind];
  }
  else {
    fprintf(stderr,"No filename specified\n");
  	exit(1);
  }
  
  /* Now open file. First check if append or overwrite is required */
  if (useAppend) {
    fp = fopen(filename,"a");
  }
  else {
    fp = fopen(filename,"w");
  }
  
  /* start reading characters and send them to the file and stdout 
  *  until End-of-file (EOF) is found.
  */
  char ch = getchar();
  while (ch != -1) {
    fputc(ch, fp); 
    fputc(ch, stdout);
    ch = getchar();  
  }
  /* close the file */
  fclose(fp);

}
