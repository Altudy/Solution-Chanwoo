#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//TDEF
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

//GLOB
int N;
vll A;
vll B;
vll D;
int Bsize;

//FUNC
void input() {
	cin >> N;
	A.assign(N, 0L);
	for (int i = 0; i < N; i++)
		cin >> A[i];
}

void pre() {
	sort(A.begin(), A.end());
	ll temp = A[0];
	ll sum(temp);
	for (int i = 1; i < N; i++) {
		if (temp == A[i])
			sum += A[i];
		else {
			if (temp + 1 == A[i])
				B.push_back(sum);
			else {
				B.push_back(sum);
				B.push_back(0);
			}
			sum = (temp = A[i]);
		}
	}
	B.push_back(sum);
}

void sol() {
	Bsize = B.size();
	D.assign(Bsize, 0);
	D[0] = B[0];
	if (Bsize < 2) return;
	D[1] = max(B[0], B[1]);
	for (int i = 2; i < Bsize; i++) {
		D[i] = max(D[i - 1], D[i - 2] + B[i]);
	}
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	pre();
	sol();
	cout << D[Bsize-1];
	return 0;
}
