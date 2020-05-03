/* #lev3 #DP #DFS */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include <map>
#include <iomanip>
#include <functional>
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
typedef unsigned int			uint;
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/
int n;
vi a, dp, ans;
vvi e;

void dfs(int now, int pre){
	int pos = lower_bound(dp.begin(), dp.begin()+n, a[now]) - dp.begin();
	int dp_hist = dp[pos];
	dp[pos] = a[now];
	ans[now] = lower_bound(dp.begin(), dp.begin()+n, inf) - dp.begin();
	
	for(uint i=0; i < e[now].size(); i++){
		int v = e[now][i];
		if(pre == v) continue;
		dfs(v, now);
	}
	
	dp[pos] = dp_hist;
}

void sol() {
	cin >> n;
	a.resize(n + 1);
	dp.assign(n , inf);
	ans.resize(n +1);
	e.assign(n + 1, vi());
	
	for(int i=1; i <= n;i++) 
		cin >> a[i];
		
	for(int i=1; i<n;i++){
		int u, v; 
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
		
	dfs(1, -1);
	for(int i=1; i<= n;i++)
		cout << ans[i] << '\n';
	
}         

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
	sol();
    return 0;
}
