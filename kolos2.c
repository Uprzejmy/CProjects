#include <stdio.h>
#include <stdlib.h>

int main()
{
  int indexNumber = 115160;
  
  srand(indexNumber);
  
  printf("Wylosowana liczba to: %d",(rand()%4)+1);

  return 0;
}
