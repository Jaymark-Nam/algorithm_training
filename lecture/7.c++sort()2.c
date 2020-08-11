
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<string, pair<int, int>>a, pair<string, pair<int, int>>b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}

int main(void) {
	vector<pair<string, pair<int, int>>> v;
	v.push_back(pair<string, pair<int, int>>("A", pair<int,int>(90,20000303)));
	v.push_back(pair<string, pair<int, int>>("B", pair<int, int>(90, 20911203)));
	v.push_back(pair<string, pair<int, int>>("C", pair<int, int>(40, 19950213)));
	v.push_back(pair<string, pair<int, int>>("D", pair<int, int>(60, 20040915)));
	v.push_back(pair<string, pair<int, int>>("E", pair<int, int>(50, 19980123)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout<< v[i].first<<" ";
	}
	return 0;
}