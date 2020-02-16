/* #lev4 #아이디어 #Math                         */

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
constexpr long long     MOD = 1000000007LL;
/*************************************************/
#define  it(x)  x.begin() 
void sol() {
	int n;
	string s;
	cin >> n >> s;

	vi t;
	for (int i = n; i >= 1; i--) t.push_back(i);
	for (int i = 0; i < n; i++) {
		int j = i;
		while (s[j] == '<') j++;
		reverse(it(t) + i, it(t) + j + 1);
		i = j;
	}
	for (int i = 0; i < n; i++) cout << t[i] << " ";
	cout << '\n';

	for (int i = 1; i <= n; i++) t[i - 1] = i;
	for (int i = 0; i < n; i++) {
		int j = i;
		while (s[j] == '>') j++;
		reverse(it(t) + i, it(t) + j + 1);
		i = j;
	}
	for (int i = 0; i < n; i++) cout << t[i] << " ";
	cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

	int T; cin >> T;
	while (T--)
		sol();

    return 0;
}
