include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define MAX_ll 9000000000000000000 //9*10^18 정도가 최대값.

//TDEF
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<bool> vb;
typedef vector<char> vch;
typedef pair<ll, ll> pii;

/*****Actual Code******/
//GLOB
ll N, mx(0);
vi DP, A;

//FUNC
void input() {
	cin >> N;
	DP.assign(100000, -1LL);
	A.assign(100000, 0LL);
	ll temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A[temp]++;
		mx = max(mx, temp);
	}
}
//num은 양의 개념, n은 index개념.
ll sol(ll n) {
	if (n <= 0)
		return 0;
	if (DP[n] != -1)
		return DP[n];
	

	return DP[n] = max(sol(n - 1), A[n] * n + sol(n - 2)); //갱신과 동시에 return.
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	cout << sol(mx) << '\n';
	return 0;
}
