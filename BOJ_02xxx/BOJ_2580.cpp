#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

//TDEF
using namespace std;
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;

//GLOB
int D[9][9];				//스도쿠 배열 저장
vector<pii> blank;			//비어 있는 칸의 인덱스 저장
int blankSize;				//비어있는 칸의 개수
vector<si> miniSq, row, col;//각 행, 각 열, 각 작은 정사각형에서 빠진 숫자가 무엇인지 집합으로 저장.
si init = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };//초기값
bool solved(false);			//문제해결하면 true.
//FUNC

void fill_this(int i, int j) { //miniSq, row, col에 D[i][j]에 있는 값이 넣어졌다고 알려줌
	row[i].erase(D[i][j]);
	col[j].erase(D[i][j]);
	miniSq[3 * (j / 3) + i / 3].erase(D[i][j]);
}

void erase_this(int i, int j) {//miniSq, row, col에 D[i][j]에 있는 값이 빠질 것이라고 알려줌
	int k = 3 * (j / 3) + i / 3;

	row[i].insert(D[i][j]);
	col[j].insert(D[i][j]);
	miniSq[k].insert(D[i][j]);
}

void input() {
	for (int i = 0; i < 9; i++) {	//모든, 행,열,miniSq가 비어있을때.
		miniSq.assign(9, init);
		row.assign(9, init);
		col.assign(9, init);
	}
	for(int i=0; i<9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> D[i][j];
			if (D[i][j] == 0)		//0이면, blank에 추가, 아니면 fill_this.
				blank.push_back(pii(i, j));
			else
				fill_this(i, j);
		}
	blankSize = blank.size();
}



bool is_possible(int i, int j, int num) {
	int k = 3 * (j / 3) + i / 3;
	if (row[i].find(num) == row[i].end()
		|| col[j].find(num) == col[j].end()
		|| miniSq[k].find(num) == miniSq[k].end())
		return false;
	else
		return true;
}

void sol(int idx) { //Backtracking으로 해결.
	if (idx == blankSize) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << D[i][j] << " ";
			cout << "\n";
		}
		solved = true;
		return;
	}
		

	int x = blank[idx].first, y = blank[idx].second;
	for (int num = 1; num <= 9; num++) {
		if (solved)
			break;
		if (is_possible(x, y, num)) {
			D[x][y] = num;
			fill_this(x, y);
			sol(idx + 1);
			erase_this(x, y);
			D[x][y] = 0;
		}
	}
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	sol(0);
	return 0;
}

/* for test

	for (int i = 0; i < 9; i++) {
		cout << "row : ";
		for (si::iterator it = row[i].begin(); it != row[i].end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	for (int i = 0; i < 9; i++) {
		cout << "col : ";
		for (si::iterator it = col[i].begin(); it != col[i].end(); ++it)
			cout << *it << " ";
		cout << endl;
	}

	for (int i = 0; i < 9; i++) {
		cout << "miniSq : ";
		for (si::iterator it = miniSq[i].begin(); it != miniSq[i].end(); ++it)
			cout << *it << " ";
		cout << endl;
	}

*/
