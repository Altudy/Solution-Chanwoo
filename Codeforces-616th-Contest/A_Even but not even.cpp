/* #lev1  #구현          */
 
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
int N, T;
char c[3000];
 
void sol() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> c[i];
    int sum(0), hi(-1), lo(-1);
    for (int i = N - 1; i >= 0; i--) {
        int e = c[i] - '0';
        if (e % 2 == 1) {
            hi = i; break;
        }
    }
    for (int i = hi; i >= 0; i--) {
        sum += (c[i] - '0');
        if (sum % 2 == 0) {
            lo = i; break;
        }
    }
    if (hi == -1 || lo == -1) cout << -1 << '\n';
    else {
        for (int i = lo; i <= hi; i++)
            cout << c[i];
        cout << '\n';
    }
 
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
