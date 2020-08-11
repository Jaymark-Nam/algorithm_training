
//bubble sort

//가장 효율성이 떨어짐.

#include <stdio.h>
int main(void) {
	int i, j, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 2,3, 4, 9 };
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		print("%d", array[i]);
	}
	return 0;
}