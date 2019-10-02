#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> div;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		div.push_back(temp);
	}
	sort(div.begin(), div.end());
	cout << div.front() * div.back();

	return 0;
}
