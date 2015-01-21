//gcc -g -Wall 92.c -o 92

#include <stdio.h>
#include <stdlib.h>

void lowerToUpper(char* table);
void spaceOrNumberChange(char* table);

int main () 
{
  int i;//mam obslugiwac tablice, wiec iterator sie przyda
  
  FILE* fip;//file input pointer
  FILE* fop;//file output pointer   wiem ze output file pointer lepiej brzmi, ale cos co zaczyna sie na f kojarzy mi sie z file
  
  int numberOfChars;//ilosc znakow w input file
  char* table;//tablica do ktorej skopiuje zawartosc pliku
  
  fip=fopen("argument2.txt", "r");//otwieram pierwszy plik w trybie odczytu
  fop=fopen("output2.txt", "w+");//otwieram drugi plik w trybie zapisu (nalezy odroznic nadpisywanie - w, od dopisywania - a) i odczytu (zostawilem odczyt jakbym chcial cos debugowac)
  
  //tu jest sprytny kawalek ktorym posluzylem sie do wyliczenia ilosci znakow w input file
  //jak otwieram plik za pomoca fopen, to otrzymuje wskaznik na plik (fip), oraz iterator do przechodzenia po pliku, ktory domyslnie wskazuje na poczatek pliku (nie widac go, ale jest)
  //o pliku polecam w uproszczeniu myslec jak o tablicy, ten ww iterator to bedzie i ktore sluzy do chodzenia po tablicy za pomoca for
  fseek(fip,0,2);//przesuwam iterator pliku na ktory wskazuje fip na pozycje 0 od konca(!) (mode (argument3) = 2 powoduje ze offset (argument2) o ktory sie przesuwamy bedzie liczony od konca)
  numberOfChars=ftell(fip);//ftell zwraca aktualna pozycje w pliku (jestem na koncu, wiec tym samym dostaje ilosc znakow)
  fseek(fip,0,0);//wracam na poczatek pliku (mode (argument3) = 0 oznacza ze offset o ktory sie przesuwamy liczony jet od poczatku pliku)

  //alokuje pamiec na tablice (tablica dynamiczna)
  table = (char*) malloc(numberOfChars * sizeof(char));//cos niejasne?
  fread(table,sizeof(char),numberOfChars,fip);//wpisuje zawartosc pliku do pamieci (w tym wypadku wskaznik na poczatek tablicy)
  
  //to jest podane instrukcji do zadania
  lowerToUpper(table);
  spaceOrNumberChange(table);
  
  //kazdy znak z tablicy wpisuje do pliku
  for(i=0;i<numberOfChars;i++)
  {
    fprintf(fop, "%c", table[i]);
  }
 
  //zamykam pliki, mowil prowadzacy w jakich sytuacjach cos moze sie skaszanic jak nie zamkniemy 
  fclose(fip);
  fclose(fop);//tu to zamkniecie jest OBOWIAZKOWE w moim programie, poniewaz nie drukowalem do pliku "recznie" znaku konca pliku. flose zrobi to za mnie
  free(table);//dokladnie tak samo jak z zamykaniem plikow. NALEZY to robic

	return 0;
}


//odnosnie dwoch nastepnych funkcji, ja wiem ze czesc sie powtarza, ale dbarnas kazal mi przekazac wskaznik na tablice do funkcji i niech one same sie martwia.
void lowerToUpper(char* table)
{
  int length=0;
  int i;

  while(table[length++]);//piekne. dbarnas podal to w instrukcji. Ta petla poprostu przechodzi po tablicy i zlicza ilosc elementow

  for(i=0; i<length; ++i)
  {
    if(table[i]>='a' && table[i]<='z') table[i]=table[i]-'a'+'A';
  }
  
  return;
}

void spaceOrNumberChange(char* table)
{
  int length=0;
  int i;

  while(table[length++]);

  //(rand() % n) - random integer between [0,n].
  //Metoda szukania losowej liczby bardzo słaba, ale na potrzeby zadania wystarczy
  //Dla chcących się dowiedzieć dlaczego: http://c-faq.com/lib/randrange.html oraz http://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range
  for(i=0; i<length; ++i)
  {
    if(table[i]==' ') table[i]='_';
    if(table[i]>='0' && table[i]<='9') table[i] = (rand() % 9) + '0';
  }

  return;
}
