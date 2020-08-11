
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	vector<pair<int, string>> v;
	v.push_back(pair<int, string>(90, "A"));
	v.push_back(pair<int, string>(80, "B"));
	v.push_back(pair<int, string>(70, "C"));
	v.push_back(pair<int, string>(99, "D"));
	v.push_back(pair<int, string>(50, "E"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout<< v[i].second<<" ";
	}
	return 0;
}