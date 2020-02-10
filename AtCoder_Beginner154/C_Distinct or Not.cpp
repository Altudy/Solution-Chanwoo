/* #lev1                        */
 
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
 
constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/
int N;
vi a;
 
void sol() {
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> N;
    a.resize(N);
    for (auto& x : a)
        cin >> x;
    bool ans(true);
    sort(a.begin(), a.end());
    for (int i = 0; i < N-1; i++) {
        if (a[i] == a[i + 1])
            ans = false;
    }
    if (ans) cout << "YES\n";
    else cout << "NO\n";
 
    return 0;
}
