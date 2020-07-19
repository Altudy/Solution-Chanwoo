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
#include <numeric>
//#pragma warning(disable:4996)

using namespace std;


/** Type Define **/
typedef unsigned int            uint;
typedef unsigned char           uchar;
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

ll l, r, m;

void findAns(const ll& a, const ll& res, bool op) {
    ll b, c;
    if (op) {
        b = r, c = r - res;
    }
    else {
        b = l, c = l - res;
    }
    cout << a << ' ' << b << ' ' << c << '\n';
}

void sol() { 
    cin >> l >> r >> m;

    ll xterm_l(l - r), xterm_r(r - l);

    for (ll a = l; a <= r; a++) {
        ll n = m / a, res = m % a;
        if (n > 0)
            if (res <= xterm_r) {
                findAns(a, res, 1); 
                return;
            }

        if (n >= 0)
            if ((res - a) >= xterm_l) {
                findAns(a, res - a, 0);
                return;
            }
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
