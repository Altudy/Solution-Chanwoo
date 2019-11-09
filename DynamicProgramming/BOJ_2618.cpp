#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define x first   //각 사건의 위치를 (x, y)로 쉽게 알아보기 위해.
#define y second

//(TYPE)DEF
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

//GLV
int N, W;
vector<vi> D;     //D[i][j] : 1번경찰차가 i, 2번경찰차가 j에 있는 상태에서 마지막 사건까지 해결하는 최소거리.
vector<pii> Case; //W개의 사건이 일어난 x, y좌표 저장.
vector<vi> path;  //마지막에 경로를 출력하기 위해 D[i][j]라는 값이 나왔을 때 어떤 경찰차로 진행했는지 저장.


//FUNC
void input() {
	cin >> N >> W;
	D.assign(W + 2, vi(W + 2, -1));  //D[0]과 D[1]에 초기 1,2번 경찰차의 위치를 저장하기 위해 W+2개 저장.
	Case.assign(W + 2, pii(0, 0));
	path.assign(W + 2, vi(W + 2, 0));//위 주석과 같다.
	Case[0] = pii(1, 1);
	Case[1] = pii(N, N);
	for (int i = 2; i < W + 2; i++) //사건W개: Case[2..(W+1)]
		cin >> Case[i].x >> Case[i].y;
}

int dist(const pii& a, const pii& b) {
	return abs(a.x - b.x) + abs(a.y - b.y); //절댓값 거리 반환.
}
int DP(int p1, int p2, int c) {
	if (c == W + 2) { //Case[W+2]번째 사건은 존재하지 않으므로 0반환.
		return 0;
	}

	int& chk = D[p1][p2]; //시간 초과를 해결하기 위해 중요한부분. 함수의 나머지 부분에서 D[p1][p2]에 2번 더 접근하게 되는데, 
                        //이걸 다시 불러 오는게 시간을 꽤 소요하는 것 같다.
                        //ref(&)로 처리해주지 않으면 중복계산을 없애도 시간초과가 뜬다.
	if (chk != -1)        //중복 계산을 없앤다.
		return chk;
		

	int if_p1 = DP(c, p2, c + 1) + dist(Case[p1], Case[c]); // 1번차를 Case[c]자리로 옮기고 옮긴 거리와 DP[c][p2]를 더해준다. 
	int if_p2 = DP(p1, c, c + 1) + dist(Case[p2], Case[c]); // 2번차를 Case[c]자리로 옮기고 옮긴 거리와 DP[p1][c]를 더해준다. 

	if (if_p1 < if_p2) {  //1번경찰차위치: Case[p1], 2번경찰차위치: Case[p2] 일 때, 
		path[p1][p2] = 1;   //1,2번 경찰차중 어느것으로 다음 사건을 해결하는게 끝까지 갔을 때 더 적은 시간이 걸리는지 판단
		return chk = if_p1; //DP[p1][p2]가 현재 자리에 오기까지 걸리는 거리는 신경쓰지 않는다는 것이 중요.
	}
	else {
		path[p1][p2] = 2; 
		return chk = if_p2;
	}
}



//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	cout << DP(0, 1, 2) << '\n';

	for (int p1(0), p2(1); max(p1, p2) + 1 < W + 2; ) {
		cout << path[p1][p2] << '\n';
		if (path[p1][p2] == 1)  p1 = max(p1, p2) + 1;
		else					          p2 = max(p1, p2) + 1;
	}
	
	return 0;
}
