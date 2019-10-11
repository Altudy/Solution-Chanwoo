#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; // 1<=N<=1000
	cin >> N;

	vector<int> P(N , 0); //index 0 to N-1
	for (int i = 0; i < N; i++)
		cin >> P[i];

	sort(P.begin(), P.end()); // Make P[] in not decreasing order.

	int Sum = P[0];
	for (int i = 1; i < N; i++) {
		P[i] = P[i] + P[i - 1];
		Sum += P[i];
	}

	cout << Sum;
	return 0;
}
