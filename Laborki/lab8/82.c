#include <stdio.h>
#include <string.h>

void decryptFile(char* filename);
char decryptFunction(char c);

int main (int argc, char *argv[]) 
{
  int i;

  if(argc<2)
  {
    printf("Podaj sciezke przynajmniej jednego pliku\n");

    return 1;
  }


  for(i=1;i<argc;i++)//pierwszy argument to nazwa programu, wiec jego nie bedziemy szyfrowac :)
  {
    decryptFile(argv[i]);    
  }

  return 0;
}

void decryptFile(char* filename)
{
  FILE *fip;
  FILE *fop;
  char decryptedFilename[100];
  char c;
  
  fip=fopen(filename, "r");
  strcpy(decryptedFilename, "odszyfrowany_");
  strcat(decryptedFilename, filename);
  fop=fopen(decryptedFilename,"wb");

  if(!fip)
  {
    printf("Plik %s nie istnieje\n", filename);

    return;
  }
  
  while(!feof(fip))
  {
    fscanf(fip, "%c", &c);
    fprintf(fop, "%c", decryptFunction(c));
  }
  
  // Zamknij otwarty plik (ważne!)
  fclose(fip);
  fclose(fop);

  return;
}

char decryptFunction(char c)
{
  return c+20;
}
