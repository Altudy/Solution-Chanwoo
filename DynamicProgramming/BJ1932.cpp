//Bottom_up_Approach

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	int **D = new int*[N];
	for (int i = 0; i < N; i++)
		D[i] = new int[N];

	for (int i(N-1), k(1); i >= 0; i--, k++)
		for (int j = 0; j < k; j++)
			cin >> D[i][j];
	
	for (int i(1), k(N - 1); i < N; i++, k--)
		for (int j = 0; j < k; j++)
			D[i][j] = max(D[i][j] + D[i - 1][j], D[i][j] + D[i - 1][j + 1]);

	cout << D[N - 1][0];

	return 0;
}

//Top_down_Approach
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	

	int **D = new int*[n];
	int **map = new int*[n];
	for (int i = 0; i < n; i++) {
		D[i] = new int[n];
		map[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> map[i][j];
		}
	}
	D[0][0] = map[0][0];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			D[i + 1][j] = max(D[i + 1][j], D[i][j] + map[i + 1][j]);
			D[i + 1][j + 1] = max(D[i + 1][j + 1], D[i][j] + map[i + 1][j + 1]);
		}
	}

	int Max = 0;
	for (int i = 0; i < n; i++)
	{
		Max = max(Max, D[n - 1][i]);
	}
	cout << Max << '\n';

	return 0;
}
