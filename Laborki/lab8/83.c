#include <stdio.h>
#include <string.h>

void encryptFile(char* filename);
char encryptFunction(char c);

void decryptFile(char* filename);
char decryptFunction(char c);


int main (int argc, char *argv[]) 
{
  int i = 1;

  if(argc<2)
  {
    printf("Podaj sciezke przynajmniej jednego pliku\n");

    return 1;
  }

  while(i<argc)
  {
    if(strcmp(argv[i],"-d"))//strcmp polecam zobaczyc w dokumentacji co kiedy zwraca (tutaj 0 -> stringi sa takie same)
    {
      encryptFile(argv[i]);
    }
    else
    {
      decryptFile(argv[++i]);
    }

    i++;
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

char encryptFunction(char c)
{
  return c-20;
}

char decryptFunction(char c)
{
  return c+20;
}
