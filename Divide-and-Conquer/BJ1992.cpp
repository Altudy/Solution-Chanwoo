#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
typedef vector<int> v_int;
typedef vector<vector<int>> vv_int;
typedef pair<int, int> pii;

string S;
void QT(const vv_int& M, pii start, int w); // s: start point, w: width(==height)

int main() {
	int N;
	cin >> N;
	vv_int M(N, vector<int>(N, 0)); //Map.
	pii start(0, 0);

	char input;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> input;
			M[i][j] = (int)input - 48;
		}


	QT(M, start, N);
	cout << S;

	return 0;
}
	
void QT(const vv_int& M, pii s, int w) {
	//If cell's size is 1, just 0 or 1.
	if (w == 1) {
		if (M[s.first][s.second] == 1)	::S += '1';
		else							::S += '0';
		return;
	}

	
	int sum(0); //get cell's total nubmer. if all elements are 1, sum should equal to cell's size,
				//if all elements are 0, sum should equal to 0.
	for (int i = s.first; i < s.first + w; i++)
		for (int j = s.second; j < s.second + w; j++)
			sum += M[i][j];

	//Check that whether cell's numbers is all 1 or 0.
	if (sum == w * w)
		::S += '1';
	else if (sum == 0)
		::S += '0';
	else {				//Otherwise, divide into 4 cells.
		int m = w / 2;
		::S += '(';
		QT(M, pii(s.first, s.second), m);
		QT(M, pii(s.first, s.second + m), m);
		QT(M, pii(s.first+m, s.second), m);
		QT(M, pii(s.first+m, s.second+m), m);
		::S += ')';
	}

	return;
}
