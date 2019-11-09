#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//TDEF
using namespace std;
typedef long long ll;  //중요: 입력의 범위가 10^9 였으므로 int형으로 계속 계산해나가지 못할 것을 예상했어야 했다.

//GLOB
class island {
public:
	island(char ani, int n) : animal(ani), num(n) {};
	typedef island* link;
	ll sol();
	vector<link> from;
	char animal;
	ll num;
};

int N;
vector<island> I;

//FUNC
void input() {
	char t;
	ll a;
	int p;
	cin >> N;
	I.assign(N, island('S', 0));
	for (int i = 1; i < N; i++) {
		cin >> t >> a >> p;
		I[i].animal = t;
		I[i].num = a;
		I[p - 1].from.push_back(&I[i]); //i번째 섬으로 들어오는 섬들의 주소를 vector로 저장해 놓는다.
	}
}

ll island::sol() {
	vector<link>::iterator it;
	ll sheep(0);

  //from에 저장된 섬들로부터 오는 양의 수를 센다. 재귀로 leaf노드까지 갔다가 돌아오게 된다.
	for (it = this->from.begin(); it != this->from.end(); ++it) {
		sheep += (*it)->sol();
	}

	if (animal == 'S') //현재 섬이 양이면 들어온 양과 합쳐서 보낸다.
		return sheep + this->num;
	else               //현재 섬이 늑대면 들어온 양의 수에서 늑대 수를 빼고 만약 늑대가 더 많으면 양을 보내지 않는다.
		return max(ll(0), sheep - this->num);
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	cout << I[0].sol();
	return 0;
}
