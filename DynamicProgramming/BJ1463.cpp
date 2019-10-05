#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef vector<int> v_int;

int findMinCut(int N, v_int& X);

//Simply return the smallest one.
int int_min(int n1, int n2);
int int_min(int n1, int n2, int n3);

int main() {
	int N;
	cin >> N;

	//X[i] contains the cutting number that should do for making 1 from i.
	v_int X(N + 1, 0); //What we want is X[N]. So, declare N+1. and initialize all elements to 0.

	//Base condition
	//1->1 : 0 step.
	//2->1 & 3->1 : 1 step.
	X[1] = 0; 
	if (N >= 3)
		X[3] = 1;
	if (N >= 2)
		X[2] = 1;

	//Compute
	findMinCut(N, X);

	cout << X[N];

	return 0;

}

int findMinCut(int N, v_int& X) {
	int Min(0);

	//If X[N] != 0, there already exists optimal value. Base condition is X[2]=1, X[3]=1. Bottom-Up Approach.
	//If N == 1, return;
	if (X[N] == 0 && N > 1) {
		//Compare all Possible cases and store min value.
		if (N % 3 == 0 && N % 2 == 0)
			Min = int_min(findMinCut(N / 3, X), findMinCut(N / 2, X), findMinCut(N - 1, X));
		else if (N % 3 == 0)
			Min = int_min(findMinCut(N / 3, X), findMinCut(N - 1, X));
		else if (N % 2 == 0)
			Min = int_min(findMinCut(N / 2, X), findMinCut(N - 1, X));
		else
			Min = findMinCut(N - 1, X);

		//Since processing one step, plus one.
		X[N] = Min + 1;
	}

	return X[N];
}

int int_min(int n1, int n2) {
	if (n1 <= n2)
		return n1;
	else
		return n2;
}
int int_min(int n1, int n2, int n3) {
	if (n1 <= n2) {
		if (n1 <= n3)
			return n1;
		else
			return n3;
	}
	else {
		if (n2 <= n3)
			return n2;
		else
			return n3;
	}
}
