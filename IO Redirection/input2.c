/***
  Dit programma laat zien hoe je eenvoudig input van STDIN of een bestand kunt lezen en voorzien van een regelnummer.
  
  Om dit programma te starten via Bash:
  
  user@host:~/programs$ input2 mysourcefile
  
  of 
  
   user@host:~/programs$ input2 < mysourcefile

***/

#include <stdio.h>
#include <stdlib.h>

void main(int argc, const char *argv[]){
  char *buffer = NULL;
  size_t len;
  ssize_t read;
  long linenumber = 1;
  FILE * fp;

  printf("%d argumenten\n", argc);

  if (argc == 1) {
    fp = stdin;
  }
  else{
    fp = fopen(argv[1],"r" );
  }

  while ((read = getline(&buffer, &len, fp) != -1)){
    printf("%04d:%s" , linenumber++, buffer);
  }/*while*/

  free(buffer);

  if (fp != stdin) fclose(fp);

}/* main */
