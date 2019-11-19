#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#define elem first
#define idx second
#define MAX_ll 9000000000000000000 //9*10^18 정도가 최대값.
//TDEF
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<bool> vb;
typedef vector<char> vch;
typedef pair<ll, ll> pii;
typedef vector<ll>::iterator v_it;


/*****Actual Code******/ //deque로 슬라이드 구성을 하되 딱 필요한 값만 가지고 있게 하여 검색을 하지 않게 한다.
//GLOB
int N, L;
deque<pair<int, int>> dq;

//FUNC
void input() {
	cin >> N >> L;
}

void sol() {
	int e;
	for (int i = 1; i <= N; i++) {
		while (dq.size() && dq.front().idx <= i - L)
			dq.pop_front();
		cin >> e;
		while (dq.size() && dq.back().elem >= e) //새로 들어올 애보다 큰 원소는 e가 나갈때까지 필요없는 원소이므로 배제.
			dq.pop_back();
		dq.push_back({ e, i });
		cout << dq.front().elem << " ";
	}
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	sol();
	return 0;
}
