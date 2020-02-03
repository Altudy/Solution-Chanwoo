/* #lev2 #브루트포스       */
 
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
 
template<typename T>
constexpr auto all(T x) { return x.begin(), x.end(); }
constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/
int n, m, k, T;
vi a;
 
void Mx(int& a, int b) {
    if (a < b) a = b;
}
void Mn(int& a, int b) {
    if (a > b) a = b;
}
 
void sol() {
    cin >> n >> m >> k;
    a.resize(n);
    for (auto& x : a) cin >> x;
    int ans(-1);
    int rest = m - 1 - k;
    if (rest <= 0) {
        for (int i = 0; i < m; i++) {
            int j = n - (m - i);
            //cout << "Comp : " << a[i] << ", " << a[j] << endl;
            Mx(ans, max(a[i], a[j]));
        }
    }
    else {
        int mn;
        for (int lo = 0; lo <= k; lo++) {
            int hi = n - (k - lo) - 1;
            mn = inf;
            for (int i = 0; i <= rest; i++) {
                //cout << "Comp : " << a[lo + i] << ", " << a[hi - rest + i] << endl;
                Mn(mn, max(a[lo + i], a[hi - rest + i]));
                
            }
            Mx(ans, mn);
        }
        
    }
 
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        sol();
    }
 
    return 0;
}
