/* #lev5 #Tree #DFS #Math */

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

const int MAXN = 200010, P = 1e9 + 7;
int n, x, y, _edge, _head[MAXN], _vertex[2 * MAXN], _next[2 * MAXN], _size[MAXN];
int f[MAXN]; // f[i] i를 루트로 트리를 만들었을 때, 순서가 강제되는만큼 반영. ans[i] = n! % f[i] 이 된다.

void add_edge(int x, int y) {
    _vertex[++_edge] = y;
    _next[_edge] = _head[x]; //처음엔 0, x가 바라보는 노드를 _next로 쭉 연결시킨다.
    _head[x] = _edge;
    return;
}

// fermat's theorm에서 등장하는 multiplicative inverse function.
int mul_inv_of(int _x) {
    int p = 1e9+5;
    ll x(_x), res(1);
    while (p) {
        if (p & 1) res = (res * x) % P;
        x = (x * x) % P;
        p >>= 1;
    }
    return int(res);
}

void dfs1(int x, int parent) {
    _size[x] = 1;
    for (int e = _head[x]; e; e = _next[e]) {
        if (_vertex[e] == parent) continue;
        dfs1(_vertex[e], x);
        _size[x] += _size[_vertex[e]];
    }
    f[1] = (1ll * f[1] * _size[x]) % P;
    return;
}

void dfs2(int x, int parent) {
    for (int e = _head[x]; e; e = _next[e]) {
        int y = _vertex[e];

        if (y == parent) continue;
        ll temp = 1ll * (n - _size[y]) * mul_inv_of(_size[y]) % P;
        f[y] = ( 1ll * f[x] * temp ) % P;
        dfs2(y, x);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    cin >> n;

    f[1] = 1;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        add_edge(x, y), add_edge(y, x);
    }

    dfs1(1, 0);
    dfs2(1, 0);

    int tmp = 1;
    for (int i = 1; i <= n; i++) 
        tmp = (1ll * tmp * i) % P; // n! % mod

    for (int i = 1; i <= n; i++) 
        cout << (1ll * tmp * mul_inv_of(f[i]) ) % P 
             << '\n';

    return 0;
}
