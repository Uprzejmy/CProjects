#include <stdio.h>
#include <string.h>

void encryptFile(char* filename);
char encryptFunction(char c);

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
    encryptFile(argv[i]);    
  }

  return 0;
}

void encryptFile(char* filename)
{
  FILE *fip;
  FILE *fop;
  char encryptedFilename[100];
  char c;
  
  fip=fopen(filename, "r");
  strcpy(encryptedFilename, "zaszyfrowany_");
  strcat(encryptedFilename, filename);
  fop=fopen(encryptedFilename,"wb");

  if(!fip)
  {
    printf("Plik %s nie istnieje\n", filename);

    return;
  }
  
  while(!feof(fip))
  {
    fscanf(fip, "%c", &c);
    fprintf(fop, "%c", encryptFunction(c));
  }
  
  // Zamknij otwarty plik (ważne!)
  fclose(fip);
  fclose(fop);

  return;
}

char encryptFunction(char c)
{
  return c-20;
}
