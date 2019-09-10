/***
  Dit programma laat zien hoe je eenvoudig input van STDIN kunt lezen en voorzien van een regelnummer.
  
  Om dit programma te starten via Bash:
  
  user@host:~/programs$ input1 < mysourcefile

***/
#include <stdio.h>
#include <stdlib.h>

void main(int argc, const char *argv[]){
  char *buffer = NULL;
  size_t len;
  ssize_t read;
  long linenumber = 1;

  while ((read = getline(&buffer, &len, stdin) != -1)){
    printf("%04d:%s" , linenumber++, buffer);
  }/*while*/

  free(buffer);

}/* main */
