
#include <iostream>
#include <algorithm>

using namespace std;

bool up(int a, int b) {
	return a < b;
}

bool down(int a, int b) {
	return a > b;
}



int main(void) {
	int a[10] = { 9, 3, 5, 4, 1, 10, 8, 6, 7, 2 };
	sort(a, a + 10, up); //sort 'a' to 'a+10'
	for (int i = 0; i < 10; i++) {
		cout << a[i];
	}
	sort(a, a + 10, down); //sort 'a' to 'a+10'
	for (int i = 0; i < 10; i++) {
		cout << a[i];
	}


}