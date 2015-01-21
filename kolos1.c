#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int copyFromFileToTable(int** table, char* filePath);
double average(int* table, int numberOfValues);
int dominant(int* table, int numberOfValues);

int main(int argc, char* argv[])
{
  int numberOfValues;
  int* table;
  char* filePath;
  
  filePath = (char*)malloc(1024 * sizeof(char));//maksymalna dlugosc sciezki pliku to 1024

  if(argc<2)
  {
    printf("Nie podano ścieżki jako argument programu, proszę zrobić to teraz\n");
    
    scanf("%s", filePath);
  }
  else
  {
    strcpy(filePath, argv[1]);
  }

  numberOfValues = copyFromFileToTable(&table, filePath);
  
  numberOfValues -=1;//hotfix @dbarnas@pk.edu.pl
  
  printf("Otrzymana średnia to: %lf\n", average(table, numberOfValues));    

  printf("Najczęściej występująca liczba to: %d\n", dominant(table, numberOfValues));
  
  free(table);
  free(filePath);

  return 0;
}

int copyFromFileToTable(int** table, char* filePath)
{
  FILE* fip;
  int i,numberOfValues;//ilosc liczb w pliku

  fip=fopen(filePath, "r");

  fscanf(fip, "%d", &numberOfValues);//wczytuje ilosc liczb do odczytania

  *table = (int*)malloc(numberOfValues * sizeof(int));//alokacja pamieci na tablice

  for(i=0;i<numberOfValues;i++)
  {
    fscanf(fip, "%d", &(*table)[i]);//wczytuje liczby do tablicy
  }

  return numberOfValues;
}

double average(int* table, int numberOfValues)
{
  int i;
  double sum=0;
  
  for(i=0;i<numberOfValues;i++)
  {
    sum+=table[i];
  }
  
  return sum/numberOfValues;
}

int dominant(int* table, int numberOfValues)
{
  int i;
  int dominantIndex=0;//jaka liczba wystepowala najczesciej
  int digitsArray[11];
  
  for(i=0;i<numberOfValues;i++)
  {
    digitsArray[table[i]]++;
  }
  
  for(i=0;i<11;i++)
  {
    if(digitsArray[i]>digitsArray[dominantIndex])
    {
      dominantIndex = i;
    }
  }
  
  return dominantIndex;
}
