//Compact ver.

#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000001];

int main() {
	int N;

	cin >> N;

	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;  //+1 always
		if (!(i % 3))DP[i] = min(DP[i / 3] + 1, DP[i]); //Compare with *3
		if (!(i % 2))DP[i] = min(DP[i / 2] + 1, DP[i]); //Compare with *2
    //store
	}

	cout << DP[N];

	return 0;
}
