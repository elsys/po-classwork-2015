#include <stdio.h>

int give_me(char[1024], int[1024], int);
void take_back(char[1024], int[1024], int);
void memory_dump(int [1024]);
void clear_memory(int [1024]);
int how_many_free(int [1024]);
int is_there_free(int [1024]);

int main() {
	int my_helper[1024];
	char my_memory[1024];
	
	clear_memory(my_helper);
	// memory_dump(my_helper);
	printf("free = %d\n", how_many_free(my_helper));
	give_me(my_memory, my_helper, 1);
	printf("free = %d\n", how_many_free(my_helper));
	printf("is there free = %s\n", is_there_free(my_helper) ? "Yes" : "No");
	
	return 0;
}

void clear_memory(int array[1024]) {
	int elem = 0;
	for (; elem < 1024; ++elem) {
		array[elem] = 0;
	}
}

int how_many_free(int helper[1024]) {
	int elem = 0, free_elements = 1024;
	for (; elem < 1024; ++elem) {
		free_elements -= helper[elem];
	}
	return free_elements;
}

int is_there_free(int helper[1024]) {
	return how_many_free(helper);
}

void memory_dump(int helper[1024]) {
	int elem = 0;
	for(; elem < 1024; ++elem) {
		if (helper[elem]) {
			printf(" #");
		} else {
			printf(" *");
		}
	}
	printf("\n");
}

int give_me(char memory[1024], int helper[1024], int size) {
	// forget about memory, we don't care about it
	int elem = 0;
	for (; elem < 1024; ++elem) {
		if (!helper[elem]) {
			
			int check = elem;
			for (; check < (elem + size); ++check) {
				if (helper[check]) {
					break;
				}
			}
			
			// Mark memory as taken
			for (check = elem; check < (check + size)); ++check) {
				helper[check] = 1;
			}
			
			helper[elem] = 1;
			return elem;
		}
	}
	return -1;
}

void take_back(char memory[1024], int helper[1024], int location) {
	
}
