//Recursion implementation
#include<iostream>
using namespace std;

int K[15], Six[15], N; 
// K	-- Subset containing N elements.
// Six	-- Subset containing 6 elements finally picked.
// N	-- K's size.

void S(int picked, int index) {
	int i;
	if (picked == 6) {
		for (i = 0; i < 6; i++)
			cout << Six[i];
		cout << "\n";
		return;
	}
	for (i = index; i <= N - 6 + picked; i++) {
		Six[picked] = K[i];
		S(picked + 1, i + 1);
		Six[picked] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);

	int i, j;
	for (j = 0;; j++) {
		cin >> N;
		if (N == 0)
			break;
		if (j > 0)
			cout << "\n";
		for (i = 0; i < N; i++)
			cin >> K[i];
		
		S(0, 0);
	}

}
