#include <iostream>
using namespace std;

int D[1001];
int N;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;

	D[0] = 0;
	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + D[i - 2]) % 10007;

	}

	cout << D[N];

	return 0;
}
