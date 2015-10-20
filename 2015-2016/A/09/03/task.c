#include <stdio.h>
#include <string.h>

int isNumber(char n[100]);
char number[100] = "1234";

int main ()
{
	int i;
	
	char entered[100];

	do {
	scanf("%s", entered);
	} while(!isNumber(entered));
	
	
		
	return 0;	
}


int isNumber(char n[100])
{
	int i;
	if (n[4] != '\0' || strlen(n) != 4) return 0;
	for (i = 0; i < strlen(n); i++)
		if (!(n[i] >= '0' && n[i] <= '9'))
			return 0;
	return 1;
}