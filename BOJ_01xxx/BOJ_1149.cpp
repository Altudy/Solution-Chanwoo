#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define R 0
#define G 1
#define B 2
//TDEF
using namespace std;

//GLOB
int N;
int W[1000][3];
int D[1000][3];

//FUNC
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> W[i][R] >> W[i][G] >> W[i][B];
}

void sol() {
	D[0][R] = W[0][R];
	D[0][G] = W[0][G];
	D[0][B] = W[0][B];
	for (int i = 1; i < N; i++) {
		D[i][R] = min(D[i - 1][G] + W[i][R], D[i - 1][B] + W[i][R]);
		D[i][G] = min(D[i - 1][R] + W[i][G], D[i - 1][B] + W[i][G]);
		D[i][B] = min(D[i - 1][R] + W[i][B], D[i - 1][G] + W[i][B]);
	}
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	sol();
	cout << min(D[N - 1][R], min(D[N - 1][G], D[N-1][B]));
	return 0;
}
