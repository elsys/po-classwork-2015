#include <stdio.h>

void print_binary(int number);

int main() {

	int a = 47;
	int b = 73;

	print_binary(a);
	print_binary(b);
	// print_binary(a | b);



	return 0;
}

void print_binary(int number) {
	printf("number: %d\tbinary: ", number);
	for(int i = sizeof(number)*8-1; i >= 0 ; i--) {
		if( (number >> i) & 1 ) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
}
