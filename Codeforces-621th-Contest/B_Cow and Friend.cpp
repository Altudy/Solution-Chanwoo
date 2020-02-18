/* #lev2 #그리디   */

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

void MX(ll& a, ll& b) {
    if (a < b) a = b;
}
void sol2() {
    ll n, x, e, mx(-1);
    cin >> n >> x;
    bool chk(false);

    while (n--) {
        cin >> e;
        if (e == x) chk = true;
        MX(mx, e);
    }

    if (chk) { cout << "1\n"; return; }
    
    //x가 mx로 나누어 떨어질 때와 나누어 떨어지지 않을 때를 동시에 커버가능.
    // 만약 나누어 떨어진다면 -1을 통해 mx를 더하여도 1이 증가하지 않게 해줄것이고
    // 나누어 떨어지지 않는다면, -1을 한다고 하더라도 x/mx + 1 과 답이 같을 것이다.
    cout << max(2LL, (x + mx - 1) / mx) << '\n';
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--)
        sol2();

    return 0;
}
