#include <stdio.h>

int is_binary_palindrome(int);

int main() {

	int number;
	scanf("%d", &number);

	printf("%d\n", is_binary_palindrome(number));

	return 0;
}

int is_binary_palindrome(int number) {
	// 101 (5) & 
	// 010
	// 001 << 1 => 010
	printf("sizeof: %d\n", sizeof(int));

	int offset = -1;
	for(int i = 0; i < 8*sizeof(int); i++) {
		if(number & (1 << i)) {
			offset = i;
		}
	}

	printf("offset: %d\n", offset);
}

