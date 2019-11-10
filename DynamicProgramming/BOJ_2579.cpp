#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//TDEF
using namespace std;
typedef vector<int> vi;

//GLOB
vi S; //each step's weight.
vi W;
int N;
 

//FUNC
void input() {
	cin >> N;
	S.assign(N + 1, 0); W.assign(N + 1, 0);
	S[0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> S[i];
}

void DP(){
	W[0] = 0; W[1] = S[1];
	W[2] = S[1] + S[2];

	for (int i = 3; i <= N; i++)
		W[i] = max(W[i - 2] + S[i], W[i - 3] + S[i - 1] + S[i]);
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	DP();
	cout << W[N];
  
	return 0;
}
