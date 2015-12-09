#include <stdio.h>

void notify_full(int[16][6]);
void empty_plane(int[16][6]);
void take_place(int[16][6], int);
void print_plane(int[16][6]);

int main() {
	int airplane[16][6];
	
	empty_plane(airplane);
	take_place(airplane, 1);
	print_plane(airplane);
	printf("\n");
	take_place(airplane, 2);
	print_plane(airplane);
	printf("\n");
	
	return 0;
}

void take_place(int airplane[16][6], int persons) {
	int row = 0, col = 0;
	
	switch(persons) {
		case 1:
		for (; row < 16; ++row) {
			for (col = 0; col < 6; ++col) {
				if (!airplane[row][col]) {
					airplane[row][col] = 1;
					return;
				}
			}
		}
		break;
		case 2:
		for (; row < 16; ++row) {
			for (col = 0; col < 6; ++col) {
				if (col != 2 && col != 5) {
					if (airplane[row][col] == 0 && airplane[row][col+1] == 0){
						airplane[row][col] = 2;
						airplane[row][col+1] = 2;
						return;
					}
				}
			}
		}
		break;
		case 3:
		for (; row < 16; ++row) {
			for (col = 0; col < 6; ++col) {
				if (col == 0 || col == 3) {
					if (airplane[row][col] == 0 
						&& airplane[row][col+1] 
							&& airplane[row][col+2]) {
								airplane[row][col] = 3;
								airplane[row][col+1] = 3;
								airplane[row][col+2] = 3;
								return;
							}
				}
			}
		}
		break;
	}
}

void empty_plane(int airplane[16][6]) {
	int row = 0, col = 0;
	for (; row < 16; ++row) {
		for (col = 0; col < 6; ++col) {
			airplane[row][col] = 0;
		}
	}
}

void notify_full(int airplane[16][6]) {
	int row = 0, col = 0;
	
	for (; row < 16; ++row) {
		for (col = 0; col < 6; ++col) {
			if (!airplane[row][col]) {
				return;
			}
		}
	}
	
	printf("Airplane is full!\n");
}

void print_plane(int airplane[16][6]) {
	int row = 0, col = 0;
	
	for (; row < 16; ++row) {
		for (col = 0; col < 6; ++col) {
			if (col == 3) {
				printf("| ");
			}
			printf("%c ", airplane[row][col] ? airplane[row][col] + '0' : '_');
		}
		printf("\n");
	}
}
