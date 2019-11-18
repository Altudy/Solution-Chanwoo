#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define MAX_ll 9000000000000000000 //9*10^18 정도가 최대값.
//TDEF
using namespace std;
typedef vector<int> vi;

/**********Actual Code***********/
//GLOB
int n; // 1 <= n <= 100,000
vi S;  // -1,000 <= S_i <= 1,000 인 정수

//FUNC
void input() {
	cin >> n;
	S.assign(n+1, 0);
	for (int i = 1; i <= n; i++)
		cin >> S[i];
}

int sol() {
	for (int i = 1; i <= n; i++)
		if (S[i - 1] + S[i] > S[i])
			S[i] = S[i - 1] + S[i];
	
	int mx = -2000000000;
	for (int i = 1; i <= n; i++)
		if (S[i] > mx)
			mx = S[i];
	return mx;
}

int sol_2() {
	int sum = 0;
	int mx = -2000000000;
	for (int i = 0; i < n; i++) {
		sum += S[i];
		mx = max(mx, sum);
		if (sum < 0) sum = 0;
		//cout << "when i is " << i << " mx is " << mx << '\n';
	}
	return mx;
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	//cout << sol() << '\n';
	cout << sol_2() << '\n';

	return 0;
}
