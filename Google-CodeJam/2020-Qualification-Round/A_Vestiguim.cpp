/* #lev1 #브루트포스 */

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

void sol() {
    int n; cin >> n;
    vvi M(n, vi(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];

    int trace(0);
    for (int i = 0; i < n; i++)
        trace += M[i][i];

    int rows(0);
    for (int i = 0; i < n; i++) {
        vi chk(n + 1, 0);
        for (int j = 0; j < n; j++) {
            if (chk[M[i][j]]++ > 0) {
                rows++;
                break;
            }
        }
    }

    int cols(0);
    for (int i = 0; i < n; i++) {
        vi chk(n + 1, 0);
        for (int j = 0; j < n; j++) {
            if (chk[M[j][i]]++ > 0) {
                cols++;
                break;
            }
        }
    }
    cout << trace << ' ' << rows << ' ' << cols;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        sol();
        cout << '\n';
    }

    return 0;
}
