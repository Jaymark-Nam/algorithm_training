#include <stdio.h>

int main(void) {
	int i, j, min, index, temp;
	int array[10] = { 1, 10, 4, 7, 5, 6, 2, 3, 9, 8 };
	for (i = 0; i < 10; i++) {
		min = 10000;
		for (j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for (i = 0; i < 10; i++) {
		printf("%d", array[i]);
			
	}
	return 0;
}