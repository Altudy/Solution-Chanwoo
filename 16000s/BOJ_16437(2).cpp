#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
const int MAXN = 123457;

struct point {
	char t;
	ll a, p;
	point() {};
	point(char _t, ll _a, ll _p) :t(_t), a(_a), p(_p) {};
};

int n;
int degree[MAXN]; // degree[i] i섬으로 (나가는X)들어오는 길이 몇개나 있는지 저장. 
point arr[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 2; i <= n; i++) {
		cin >> arr[i].t >> arr[i].a >> arr[i].p;
		if (arr[i].t == 'W') arr[i].a *= -1LL;    //늑대면 음수로 저장.
		degree[arr[i].p]++;
	}

	queue<int> q;

	for (int i = 2; i <= n; i++) {
		if (degree[i] == 0) q.push(i); //leaf노드를 q에 먼저 저장
	}

	while (!q.empty()) {
		int cur = q.front();    //q에서 먼저 하나를 뽑고
		q.pop();
		int next = arr[cur].p;  

		if (cur == 1) {         //1번 섬에 도착했으면 root에 도달한것이므로 종료.
			cout << arr[cur].a << "\n";
			break;
		}

		degree[next]--;         //next에 들어오는 경로하나를 처리했으므로 -1.

		if (degree[next] == 0) q.push(next); //next로 들어오는 경로가 없으면 q에 추가.

		if (arr[cur].t == 'S') {            //cur이 양섬이었으면 next에 그만큼 추가.
			arr[next].a += arr[cur].a;
		}
		else if (arr[cur].t == 'W') {       //cur이 늑대섬이었으면,
			if (arr[cur].a > 0) {             //cur의 섬에 남은 양이 있었을때만,
				arr[next].a += arr[cur].a;      //next섬에 양의 수만큼 추가.
			}
		}
	}

	return 0;
}
