#include <stdio.h>

char toUppercase(char x);
char toLowercase(char x);

int main (void) 
{
	int TEXTSIZE = 50;

	int i;
	char text[TEXTSIZE];
	char upperText[TEXTSIZE];
	char lowerText[TEXTSIZE];

	for(i=0; i<TEXTSIZE; i++);
	{
		text[i] = upperText[i] = lowerText[i] = 0;
	}
	
	printf("Podaj tekst do zmiany\n");
	scanf("%s",text);
	
	for(i=0; text[i]!=0; i++)
	{
		printf("%c %c %c\n",text[i],toUppercase(text[i]),toLowercase(text[i]));
		upperText[i] = toUppercase(text[i]);
		lowerText[i] = toLowercase(text[i]);
	}

	printf("tekst %s zmieniony funkcją toUppercase stał się %s\n",text,upperText);
	printf("tekst %s zmieniony funkcją toLowercase stał się %s\n",text,lowerText);

	return 0;
}

char toUppercase(char x)
{
	if(x>='a' && x<='z') return (x-'a'+'A');
	return x;
}

char toLowercase(char x)
{
	if(x>='A' && x<='Z') return (x-'A'+'a');
	return x;
}
