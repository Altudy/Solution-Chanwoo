#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, Max(0);
	cin >> N;

	//D[i][j] == X[i]*X[i+1]*~*X[j-1]*X[j]
	int** D = new int*[N];
	for (int i = 0; i < N; i++)
		D[i] = new int[N];

	for (int i = 0; i < N; i++)
		cin >> D[i][i];


	//D mapping
	for (int diag = 1; diag < N - 3; diag++)
		for (int i = 0, j = i + diag; i < N - diag; i++, j++) 
			D[i][j] = D[i][j - 1] * D[j][j];
		
	

	int Max(0);
	for (int line1 = 0; line1 <= N - 4; line1++) 
		for (int line2 = line1 + 1; line2 <= N - 3; line2++) 
			for (int line3 = line2 + 1; line3 <= N - 2; line3++) 
				Max = max(Max, D[0][line1] + D[line1 + 1][line2] + D[line2 + 1][line3] + D[line3 + 1][N - 1]);
	
	
	cout << Max;

	return 0;
}
