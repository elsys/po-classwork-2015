#include <stdio.h>

int is_prime(int *);

int main()
{
	int answer;
	int number;
	int *refernce_of_a = &number;
	
	scanf("%d",refernce_of_a);
	
	answer = is_prime(&number);
	
	printf("%d",answer);
}

int is_prime(int *numb)
{
	int counter;
	
	for(counter =  0; counter <= *numb/2; counter++)
	{
		if(counter * counter == *numb)
		{
			return 0;
		}
	}
	return 1;
}
