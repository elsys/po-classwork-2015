#include <stdio.h>
#define MAX_ROWS 16
#define MAX_COLUMNS 6

void print_airplane(int [MAX_ROWS][MAX_COLUMNS]);
int seat_person(int [MAX_ROWS][MAX_COLUMNS]);
int is_airplane_full(int [MAX_ROWS][MAX_COLUMNS]);
int seat_group_of_two(int [MAX_ROWS][MAX_COLUMNS]);

int main() {
	int seats[MAX_ROWS][MAX_COLUMNS];

	for(int i = 0; i < MAX_ROWS; i++) {
		for(int j = 0; j < MAX_COLUMNS; j++) {
			if(i != 12) {
				seats[i][j] = 0;
			} else {
				seats[i][j] = -666;
			}
		}
	}

	printf("seated 1? %d\n", seat_person(seats));
	printf("seated 1? %d\n", seat_person(seats));
	printf("seated 2? %d\n", seat_group_of_two(seats));
	printf("seated 2? %d\n", seat_group_of_two(seats));
	print_airplane(seats);

	printf("is plane full? %d\n", is_airplane_full(seats));

	return 0;
}

void print_airplane(int seats[MAX_ROWS][MAX_COLUMNS]) {
	for(int i = 0; i < MAX_ROWS; i++) {
		for(int j = 0; j < MAX_COLUMNS; j++) {
			if(i != 12) {
				printf("%d", seats[i][j]);
			}
			if(j == 2) {
				printf("  ");
			}
		}
		printf("\n");
	}
}

int seat_person(int seats[MAX_ROWS][MAX_COLUMNS]) {
	int result = 0;

	for(int i = 0; !result && i < MAX_ROWS; i++) {
		for(int j = 0; !result && j < MAX_COLUMNS; j++) {
			if(seats[i][j] == 0) {
				seats[i][j] = 1;
				result = 1;
			}
		}
	}

	return result;
}

int is_airplane_full(int seats[MAX_ROWS][MAX_COLUMNS]) {
	for(int i = 0; i < MAX_ROWS; i++) {
		for(int j = 0; j < MAX_COLUMNS; j++) {
			if(!seats[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

int seat_group_of_two(int seats[MAX_ROWS][MAX_COLUMNS]) {
	for(int i = 0; i < MAX_ROWS; i++) {
		for(int j = 0; j < MAX_COLUMNS-1; j++) {
			if( seats[i][j] == 0 &&
				seats[i][j+1] == 0 &&
				j != 2) {
				seats[i][j] = 2;
				seats[i][j+1] = 2;
				return 1;
			}
		}
	}
	return 0;
}