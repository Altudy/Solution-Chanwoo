#include <iostream>
#include <string>
#include <limits.h>
#include <vector>
#include <algorithm>
#define x first
#define y second

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<bool> vb;
typedef vector<char> vch;
typedef pair<ll, ll> pii;
using namespace std;

int test_case;
int T;
int N;
vi Cost;

void input() {
	cin >> T;
}

ll sol(int low) {
	ll Max = Cost[low];
	int Max_idx = low;
	for (int i = low + 1; i < N; i++)
		if (Max < Cost[i]) {
			Max = Cost[i];
			Max_idx = i;
		}
	ll profit(0);
	for (int i = low; i < Max_idx; i++)
		profit += (Max - Cost[i]);

	if (++Max_idx < N)
		profit += sol(Max_idx);

	return profit;
}

void func() {
	N = 0;  Cost.clear();
	cin >> N;
	Cost.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> Cost[i];
	}
	cout << "#" << test_case << " " 
		<< sol(0) << "\n";
}



int main(int argc, char** argv) {
	input();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		func();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
