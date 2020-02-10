/* #lev1         */
#include <iostream>
#include <iomanip>
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
/*************************************************/
int n, k;
vi a;
double p[1001];
double e[1001];
void prep() {
    p[0] = 0; e[0] = 0;
    for (int i = 1; i <= 1000; i++) {
        p[i] = p[i - 1] + i;
        e[i] = p[i] / i;
    }
}
 
void sol() {
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> n >> k;
    prep();
    queue<double> a;
    double ans(0.0);
    int x;
    for (int i = 0; i < k; i++) {
        cin >> x;
        a.push(e[x]);
        ans += e[x];
    }
    double mx(ans);
    for (int i = k; i < n; i++) {
        cin >> x;
        a.push(e[x]);
        ans -= a.front();
        ans += e[x];
        a.pop();
        if (mx < ans) mx = ans;
    }
 
    cout << mx << endl;
    
 
 
    return 0;
}
