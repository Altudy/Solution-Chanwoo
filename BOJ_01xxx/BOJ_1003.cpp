#include <iostream>
using namespace std;

typedef pair<int, int> pii;

int T, N;
int D[41][2]; //N은 40이하의 자연수 또는 0

void input() {
	cin >> T;
	D[0][0] = 1; D[0][1] = 0;
	D[1][0] = 0; D[1][1] = 1;
}

void sol(int N) {
	for (int i = 2; i <= N; i++) {
		D[i][0] = D[i - 1][0] + D[i - 2][0];
		D[i][1] = D[i - 1][1] + D[i - 2][1];
	}	
}

int main() {
	ios::sync_with_stdio(false);
	input();
	for (int i = 0; i < T; i++) {
		cin >> N;
		sol(N);
		cout << D[N][0] << " " << D[N][1] << "\n";
	}
		
	return 0;
}
