#include<stdio.h>
#include<string.h>

int main()
{
	char gen[5] = {"1395\0"}; // za momenta
	char user[5];
	int i, j;
	scanf("%s",user);
	for(i=0;i<strlen(user);i++)
	{
		
		if(!(user[i] >= '0' && user[i] <= '9'))
		{
			printf("samo chisla!!!");
			break;
		}
	}
	
`	for(i=0; i<4; i++) // chislata na gen
	{
		for(j=0; j<4; j++)
		{
			
		}
	}
	return 0;
}