#include <iostream>
using namespace std;

int compute(int line1, int line2, int line3, int* X, int n);

int main() {
	int n;
	cin >> n;

	int* fpt = new int[n]; //flower per tree
	for (int i = 0; i < n; i++)
		cin >> fpt[i];

	int max(0), temp;
	for (int line1 = 0; line1 <= n - 4; line1++) {
		for (int line2 = line1 + 1; line2 <= n - 3; line2++) {
			for (int line3 = line2 + 1; line3 <= n - 2; line3++) {
				temp = compute(line1, line2, line3, fpt, n);
				if (temp > max)
					max = temp;
			}
		}
	}

	cout << max;

	return 0;
}

int compute(int line1, int line2, int line3, int* X, int n) {
	int sum(0), g1(1), g2(1), g3(1), g4(1);
	for (int i = 0; i <= line1; i++) {
		g1 *= X[i];
	}
	for (int i = line1+1; i <= line2; i++) {
		g2 *= X[i];
	}
	for (int i = line2+1; i <= line3; i++) {
		g3 *= X[i];
	}
	for (int i = line3+1; i <= n-1; i++) {
		g4 *= X[i];
	}
	return g1 + g2 + g3 + g4;
}
