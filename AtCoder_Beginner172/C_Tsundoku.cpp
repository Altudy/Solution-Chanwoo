/* # */

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
int n, m, k;
vi A, B;

void Mx(ll& x, const ll& y) {
    if (x < y) x = y;
    else return;
}
void sol() {
    cin >> n >> m >> k;
    A.resize(n), B.resize(m);
    ll sum(0), cnt(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
        sum += A[i];
    }
    for (int i = 0; i < m; i++)
        cin >> B[i];

    ll ans(0);
    int ai(n - 1), bi(0);
    if (sum <= k) Mx(ans, cnt);
    while (bi < m && sum + B[bi] <= k) {
        sum += B[bi]; bi++, cnt++;
        Mx(ans, cnt);
    }

    while (ai >= 0) {
        sum -= A[ai]; ai--, cnt--;
        while (bi < m && sum + B[bi] <= k) {
            sum += B[bi]; bi++, cnt++;
            Mx(ans, cnt);
        }
    }
    cout << ans << endl;

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
