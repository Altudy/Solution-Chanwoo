// #lev2 #문자열처리
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include <map>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
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

#define all(x)  x.begin(), x.end()
#define pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     mod = 1000000007LL;
/*************************************************/

int n, m;
vi h;
vs str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	h.resize(n, 0);
	str.resize(n);
	string ans;
	string cent; //스스로 팰린드롬인 문자열 하나는 가운데에 위치할 수 있다.
	
	for (int i = 0; i < n; i++) cin >> str[i];

	for (int i = 0; i < n; i++) {
		if (h[i]) continue;
		h[i]++; //검사된 놈 구별.

		bool palin(false);
		for (int j = i + 1; j < n; j++) {
			if (h[j]) continue;
			
			palin = true;
			for (int k = 0; k < m; k++)
				if (str[i][k] != str[j][m - 1 - k]) {
					palin = false; break;
				}
			if (palin) {
				h[j]++; //검사된 놈 구별.
				ans += str[i];
				break;
			}
		}

		//짝은 존재하지 않지만, cent에 올수 있는 놈이 있으면 넣는다.
		if (!palin && cent.empty()) {
			bool palin(true);
			for (int a = 0; a < m / 2; a++)
				if (str[i][a] != str[i][m - 1 - a]) {
					palin = false; break;
				}
			if (palin) cent = str[i];
		}
	}

	int ans_size = ans.size();
	cout << (2 * ans_size + cent.size()) << endl;
	cout << ans << cent;
	for (int i = ans_size - 1; i >= 0; i--) cout << ans[i];

	return 0;

}
