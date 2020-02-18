//#lev2 #아이디어 #그리디 #constructive

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
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/
 
const int A = 26;
int n;
string s;
ll a[A];
ll b[A][A];
 
int toN(char& c) {
	return int(c - 'a');
}
void MX(ll& a, ll& b) {
	if (a < b) a = b;
}
 
int main()
{
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	cin >> s;
	n = s.size();
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < A; j++)
			b[j][toN(s[i])] += a[j];
		a[toN(s[i])]++;
	}
	ll ans = 0;
	for (int i = 0; i < A; i++) {
		MX(ans, a[i]);
		for (int j = 0; j < A; j++)
			MX(ans, b[i][j]);
	}
 
	cout << ans << endl;
 
	return 0;
}
 
