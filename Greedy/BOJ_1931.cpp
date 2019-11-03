#include<iostream>
#include<vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

int N, cnt(0);
vector<pii> T; //store time table.

void count();

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	T.assign(N, pii(0,0));

	for (int i = 0; i < N; i++)
		cin >> T[i].second >> T[i].first;

	sort(T.begin(), T.end());
	count();

	cout << cnt;

	return 0;
}

void count() {
	int start_point(0);
	for (int i = 0; i < N; i++) {
		if (start_point <= T[i].second) {
			start_point = T[i].first;
			cnt++;
		}
		else
			continue;
	}
}
