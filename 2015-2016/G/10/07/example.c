#include <stdio.h>

int main()
{
int counter=0,i,num;
int *ptr=&num;
scanf("%d", ptr);

for (i=1;i<=*ptr;i++)
	{
		if (*ptr%i==0)
		{counter++;}
	}
if(counter>2)
	{i=0;}
else
	{i=1;}
	printf("%d", i);
return 0;
}
