/* #lev2 #아이디어     */
 
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
vi a;
bool sol() {
    cin >> N;
    a.resize(N);
    for (auto& x : a) cin >> x;
    if (N & 1) {
        for (int i = 0; i < (N / 2); i++)
            if (a[i] < i || a[N - 1 - i] < i) return false;
        if (a[N / 2] < (N / 2)) return false;
    }
    else {
        for (int i = 0; i < (N / 2); i++)
            if (a[i] < i || a[N - 1 - i] < i) return false;
        if (a[N / 2] + a[N / 2 - 1] == (N - 2)) return false;
    }
 
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        if (sol())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
 
    return 0;
}
