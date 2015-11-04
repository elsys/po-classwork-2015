#include <stdio.h>
int main()
{
int number, i;
int *ptr = &number;
scanf("%d", ptr);
for(i=2; i < *ptr; i++)
{
if(*ptr % i == 0){
	printf("0 \n");
	}else printf("1 \n");
	*ptr=*ptr/i;
}
return 0;
}

