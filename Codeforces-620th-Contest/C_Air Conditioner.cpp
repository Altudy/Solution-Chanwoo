// #그리디 #lev2
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
 
 
void MN(ll& a, ll b) {
	if (a > b) a = b;
}
void MX(ll& a, ll b) {
	if (a < b) a = b;
}
void sol() {
	ll n, m, t, l, r;
	cin >> n >> m;
 
	t = 0, l = m, r = m;
	bool ans(true);
 
	for (int i = 0; i < n; i++) {
		ll ct, cl, cr;
		cin >> ct >> cl >> cr;
		ll d = ct - t;
		t = ct;
		l -= d, r += d;
 
		MX(l, cl);
		MN(r, cr);
 
		if (l > r) ans = false;
	}
 
	if (ans) cout << "YES\n";
	else cout << "NO\n";
 
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--)
		sol();
 
	return 0;
 
}
