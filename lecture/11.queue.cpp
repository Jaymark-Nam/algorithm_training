

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {
	queue<int> q;
	q.push(7);
	q.push(5);
	q.push(2);
	q.push(1);
	q.pop();
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}