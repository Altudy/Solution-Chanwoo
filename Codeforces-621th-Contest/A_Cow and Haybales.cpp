/* #lev1 #그리디   */

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
    int n, d;
    cin >> n >> d;
    vi a(n);
    for (auto& x : a)cin >> x;

    int idx = 1;
    while (idx < n && d >= idx) {
        if (idx * a[idx] <= d) {
            d -= idx * a[idx];
            a[0] += a[idx];
        }
        else {
            int x = d / idx;
            a[0] += x;
            d -= x * idx;
        }
        idx++;
    }
    cout << a[0] << '\n';
}

void sol2() {
    int n, d;
    cin >> n >> d;
    vi a(n);
    for (auto& x : a)cin >> x;
    int ans = a[0];

    for (int i = 1; i < n; i++) {
        int temp = min(d, i * a[i]);    //더 작은 것을 택함
        d -= temp;                      //d가 i로 나누어 떨어지지 않는 경우에도 d를 0으로 만들 수 있다.
        ans += temp / i;                //그럼에도 i로 정수형 division을 하면 정답만을 얻을수 있다.
        if (d == 0) break;
    }

    cout << ans << '\n';
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
