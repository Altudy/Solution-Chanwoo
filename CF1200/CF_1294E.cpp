// [Tag]
// #lev4 #구현 #아이디어 #그리디

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
//#pragma warning(disable:4996)

using namespace std;


/** Type Define **/
typedef long long int           ll;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<string>          vs;
typedef vector<bool>            vb;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;

constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;

template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T, vector<T>, greater<T> >;

/*************************************************/
char buf[131072];
int N, M;
vvi a;

//각 column에 대하여 완성시키기 위한 최소 move을 반환.
int Solve(const int& id, const vector<int>& x) {
	int ret = N;
	vi stv(N + 1, 0);

	for (int i = 1; i <= N; ++i) {
		int row_num = (x[i] + M - 1) / M; // x[i]가 있어야할 row.
		if (x[i] % M == id % M && row_num <= N)
			++stv[(i - row_num + N) % N]; // stv[i]는 i번 위로 shift했을 때 들어맞는 숫자의 개수를 가진다.
	}
		
	// i번 위로 Shift하게 되면, (N - stv[i])개의 숫자는 들어맞지 않으므로 모두 1move를 소모하여 값을 맞춰줘야한다.
	// 즉 , i번 위로 shift했을 때 불가피하게 소모되는 총 move 중 minimum을 return 하는것.
	for (int i = 0; i <= N; ++i)
		ret = min(ret, i + N - stv[i]); 
	
	return ret;
}

int main() {
	setvbuf(stdin, buf, _IOFBF, 131072);
	//int T; scanf("%d", &T);
	scanf("%d%d", &N, &M);
	a.resize(M + 1, vi(N+1));
	//int T; cin >> T;

	/* SOLVE */
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &a[j][i]);

	int ans(0);
	for (int i = 1; i <= M; ++i)
		ans += Solve(i, a[i]);
	printf("%d", ans);

	return 0;
}
