#include <stdio.h>

int main (void) 
{
  int i;
  int n = 50;//ograniczenie na znaki
  char text[n];

  printf("Proszę podać tekst do zaszyfrowania. Nie powinien być dłuższy niż 50 znaków\n");

  scanf("%s", text);

  for(i=0;i<n;i++)
  {
    if(text[i]>='A' && text[i]<='Z')
    {
      text[i] = text[i]-'A'+'a';
    }
  }

  printf("\n");

  printf("%s\n", text);

  return 0;
}
