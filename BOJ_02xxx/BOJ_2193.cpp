#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//TDEF
using namespace std;

//GLOB
int N; // 1<=N<=90;
long long D[90];

//FUNC
void input() {
	cin >> N;
	D[0] = 1;
	D[1] = 1;
}

void sol() {
	for (int i = 2; i < N; i++)
		D[i] = D[i - 1] + D[i - 2];
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	sol();

	cout << D[N - 1];

	return 0;
}
