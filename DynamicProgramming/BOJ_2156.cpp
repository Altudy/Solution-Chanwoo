#include <iostream>
#include <algorithm>
using namespace std;

int wine[10000];
int opt[10000];
int nsize;
char limit(0); //2가 되면 다음 elem넣을 수 없음.

void input();
void DP();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	DP();
    cout << opt[nsize - 1] ;
	

	return 0;
}

void input() {
	cin >> nsize;
	for (int i = 0; i < nsize; i++)
		cin >> wine[i];
}

void DP() {
	if (nsize >= 1) {
		opt[0] = wine[0];
		limit++;
	}
	if (nsize >= 2) {
		opt[1] = wine[0] + wine[1]; 
		limit++;
	}
	if (nsize >= 3) {
		int max = opt[1]; limit = 0;
		if (max < wine[0] + wine[2]) {
			max = wine[0] + wine[2];
			limit++;
		}
		if (max < wine[1] + wine[2]) {
			max = wine[1] + wine[2];
			limit = 2;
		}
		opt[2] = max;
	}
		

	for (int i = 3; i < nsize; i++) {
		if (limit == 0 || limit == 1) {
			opt[i] = opt[i - 1] + wine[i];
			limit++;
		}
		else if (limit == 2) {
			int max = opt[i - 1]; limit = 0;
			if (max < opt[i - 3] + wine[i - 1] + wine[i]) {
				max = opt[i - 3] + wine[i - 1] + wine[i]; limit = 2;
			}
			if (max < opt[i - 2] + wine[i]) {
				max = opt[i - 2] + wine[i]; limit = 1;
			}
			opt[i] = max;
		}
		else
			cout << "limit error";

	}
}
