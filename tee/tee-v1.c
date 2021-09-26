#include <stdio.h>

int main(int argc, char **argv) {

  FILE *fp;
  
  fp = fopen("tee.log","w");
  
  char c = getchar();
  while (c != -1) {
    fputc(c, fp); 
    fputc(c, stdout);
    c = getchar();  
  }
  fclose(fp);

}
