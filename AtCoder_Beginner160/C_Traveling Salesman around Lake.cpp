/* #lev1 */

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

}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;
    
    vi a(n);
    int mx(-1);
    cin >> a[0];

    int fir = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i - 1] = a[i] - a[i - 1];
        if (mx < a[i - 1])
            mx = a[i - 1];
    }

    a[n - 1] = k - a[n - 1] + fir;
    if (mx < a[n - 1])
        mx = a[n - 1];

    cout << (k - mx) << '\n';

    return 0;
}
