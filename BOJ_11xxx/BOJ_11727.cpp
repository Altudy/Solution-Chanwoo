#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//TDEF
using namespace std;


//GLOB
int n;
int D[1001];

//FUNC
void input() {
	cin >> n;
	D[0] = 1;
	D[1] = 1;
}

void sol() {
	for (int i = 2; i <= n; i++) 
		D[i] = (D[i - 1] + 2 * D[i - 2]) % 10007;
	
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	sol();
	cout << D[n];

	return 0;
}
