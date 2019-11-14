#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//TDEF
using namespace std;
typedef vector<int> vi;

//GLOB
int N;
vector<vi> D;
vector<vi> w;
vector<vector<bool>> road;

//FUNC
void input() {
	cin >> N;
	D.assign(N, vi(N, 0));
	w.assign(N, vi(N, 0));
	road.assign(N, vector<bool>(N, true)); //모든 도시가 연결되어 있다고 가정하며 시작, 필요없는 도로를 지워간다.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> D[i][j];
	for (int i = 0; i < N; i++)
		road[i][i] = false; //같은 도시간 도로는 없다.
}

bool sol() {	//Floyd's algorithm을 거꾸로 적용한다. 
				//V1 ~ Vn까지의 꼭짓점을 거치는 경로를 검사하며 거치는 경로와 같으면 road[i][j]는 지운다.
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (i == k || j == k) continue;			//본래 플로이드 알고리즘은 최소 경로를 구할 때 
				if (D[i][j] == D[i][k] + D[k][j])		//(i==k)or(j==k)여도 경로를 거치지 않는 최솟값으로 치고 저장하므로 
					road[i][j] = false;					//문제가 없지만 해당문제는 다른 vectex를 거치는 경우를 따로 고려하여 road를 제거해주어야 하므로 건너뛴다.
				
				if (D[i][j] > D[i][k] + D[k][j])		// 최소인 것으로 구해진 D[i][j]보다 더 작은 경로 존재한다면 불가능한 예제.
					return false;
			}

	return true;
}
//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();

	if (sol()) {
		int ans(0);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (road[i][j] == true)
					ans += D[i][j];
		cout << ans / 2;
	}
	else
		cout << -1;

	return 0;
}
