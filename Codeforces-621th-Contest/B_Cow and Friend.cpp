/* #lev2 #그리디                          */
 
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
 
void sol() {
    ll n, x;
    cin >> n >> x;
    vl a(n);
    for (auto& w : a) cin >> w;
 
    sort(a.rbegin(), a.rend());
    if (x % a[0] == 0) { cout << (x / a[0]) << '\n'; return; }
 
    if (x < a[0]) {
        for (int i = 1; i < n; i++)
            if (x == a[i]) {
                cout << "1\n"; return;
            }
        cout << "2\n"; return;
    }
    else {
        ll c1 = x / a[0] + 1, c2(inf);
        for (int i = 1; i < n; i++) {
            if (x % a[i] == 0) {
                c2 = x / a[i]; break;
            }
        }
        cout << min(c1, c2) << '\n';
    }
 
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
