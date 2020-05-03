/* #lev2 #브루트포스 */

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
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/
int n, m, q;
vi li;
vvi quad;
ll ans(-1);

void recur(int start, int idx) {
    if (idx == n) {
        ll sum(0);
        for (int i = 0; i < q; i++) {
            if (li[quad[i][1]-1] - li[quad[i][0]-1] == quad[i][2])
                sum += (ll)quad[i][3];
        }
        if (ans < sum) ans = sum;
    }
    else {
        for (int i = start; i <= m; i++) {
            li[idx] = i;
            recur(i, idx + 1);
        }
    }
}

void sol() {
    cin >> n >> m >> q;
    li.resize(n);
    quad.assign(q, vi(4, 0));
    for (int i = 0; i < q; i++)
        for (int j = 0; j < 4; j++)
            cin >> quad[i][j];

    ans = -1;
    recur(1, 0);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    int T(1);
    while (T--)
        sol();


    return 0;
}
