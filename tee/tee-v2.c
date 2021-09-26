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
  
  while ((c = getopt (argc, argv, "a")) != -1){
    switch (c)
      {
      case 'a':
        useAppend = true;
        break;
      case '?':
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
