#include <iostream>
#include <vector>
using namespace std;

void Greedy(vector<int>& C, int K, int& ans);

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> C(N, 0);
	for (int i = 0; i < N; i++)
		cin >> C[i];

	int ans(0);
	Greedy(C, K, ans);

	cout << ans;

	return 0;
}

void Greedy(vector<int>& C, int K, int& ans) {
	
	for (int i = C.size() - 1; i >= 0; i--) {
		if (K == 0)
			break;

		while (K >= C[i]) {
			ans += K / C[i];
			K %= C[i];
		}

	}

	return;
}
