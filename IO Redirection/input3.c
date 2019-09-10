/***
  Dit programma laat zien hoe je eenvoudig input van STDIN of een bestand kunt lezen en voorzien van een regelnummer. Het regelnummer
  en de bestandsnaam geven we nu netjes op via de command-line options methode van Linux.
  
  Om dit programma te starten via Bash:
  
  user@host:~/programs$ input3  -f mysourcefile -n 10
  
  of 
  
  user@host:~/programs$ input3 < mysourcefile -n 33
   
  of
   
  user@host:~/programs$ input3 < mysourcefile
  
***/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc,  char * const *argv){
  char *buffer = NULL;
  size_t len;
  ssize_t read;
  long linenumber = 1;
  FILE * fp;
  int opt;
  
  fp = stdin;

  while ((opt = getopt(argc, argv, "f:n:")) != -1) {
	  switch (opt) {
		  case 'f':
		    fp = fopen(optarg, "r");
		    break;
		  case 'n':
		    linenumber = atoi(optarg);
		    break;
		 default: /* '?' */
			fprintf(stderr, "Usage: %s [-f filename] [-n startnumber] \n",
			argv[0]);
			exit(EXIT_FAILURE);}
		  
  }/* switch */

  while ((read = getline(&buffer, &len, fp) != -1)){
    printf("%04d:%s" , linenumber++, buffer);
  }/*while*/

  free(buffer);

  if (fp != stdin) fclose(fp);

}/* main */
