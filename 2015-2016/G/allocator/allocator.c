#include <stdio.h>
#define MAX_SIZE 1024


void memory_dump(int[MAX_SIZE]);
void clear_memory(int[MAX_SIZE], char[MAX_SIZE]);
int how_many_free(int[MAX_SIZE]);
int is_there_free(int[MAX_SIZE]);
int give_me(char[MAX_SIZE], int[MAX_SIZE], int); 

int main() {
	int helper[MAX_SIZE];
	char memory[MAX_SIZE];
	
	clear_memory(helper, memory);
	memory_dump(helper);
	printf("Free = %d\n", how_many_free(helper));
	printf("Is there free = %d\n", is_there_free(helper));
	give_me(memory, helper, 1);
	give_me(memory, helper, 1);
	give_me(memory, helper, 1);
	give_me(memory, helper, 1);
	printf("Free = %d\n", how_many_free(helper));
	memory_dump(helper);
	
	return 0;
}

int give_me(char memory[MAX_SIZE], int helper[MAX_SIZE], int size) {
	int elem = 0;
	for (; elem < MAX_SIZE; ++elem) {
		if(!helper[elem]) {
			helper[elem] = 1;
			return elem;
		}
	}
	return -1;
}

int is_there_free(int helper[MAX_SIZE]) {
	return how_many_free(helper) ? 1 : 0;
}

int how_many_free(int helper[MAX_SIZE]) {
	int elem = 0;
	int how_many = MAX_SIZE;
	for (; elem < MAX_SIZE; ++elem) {
		how_many -= helper[elem];
		// how_many = how_many - helper[elem]
		// += , *= \=, ^=
	}
	return how_many;
}

void memory_dump(int helper[MAX_SIZE]) {
	int elem = 0;
	for (; elem < MAX_SIZE; ++elem) {
		if (helper[elem]) {
			printf(" #");
		} else {
			printf(" *");
		}
		// printf(" %c", helper[elem] ? '*' : '#')
	}
	printf("\n");
}

void clear_memory(int helper[MAX_SIZE], char memory[MAX_SIZE]) {
	int elem = 0;
	for (; elem < MAX_SIZE; ++elem) {
		helper[elem] = 0;
		memory[elem] = 0;
	}
}
