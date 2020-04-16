/* #lev2 #구현 */

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
int n, q;
ll sum(0);
vi cows,d;

void sol() {
    cin >> n >> q;
    cows.resize(n);
    d.resize(n);

    for (auto& x : cows) 
        cin >> x;
    for (int i = 0; i < n; i++) {
        d[i] = cows[i % n] * cows[(i + 1) % n] * cows[(i + 2) % n] * cows[(i + 3) % n];
        sum += (ll)d[i];
    }

    for (int i = 0; i < q; i++) {
        int f; cin >> f; f--;// Flip Sticker.
        for (int j = 0; j < 4; j++) {
            d[f] = -d[f];
            sum += ll(2 * d[f]);
            if (--f == -1) //next.
                f = n - 1;
        }
        cout << sum << '\n';
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    sol();

    return 0;
}
