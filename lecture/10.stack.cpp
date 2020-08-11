

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(2);
	s.pop();
	s.push(1);
	s.pop();
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}