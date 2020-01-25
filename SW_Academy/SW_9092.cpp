// [Tag]
// #lev3 #아이디어 #다이나믹

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
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
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;

constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;

template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T, vector<T>, greater<T> >;

/*************************************************/
int n, k;

struct p { // marathon cource [p]oint;
    int x;
    int y;
};

vector<p> P;
vvi D;

int dist(const p& A, const p& B) {
    return abs(A.x - B.x) + abs(A.y - B.y);
}

int recur(int idx, int jump) {
    if (idx == n - 1) return 0;

    int &ret = D[idx][jump];
    if (ret != inf) return ret;

    for (int j = 0; j <= jump; j++) {
        int n_idx = idx + 1 + j;
        if (n_idx > n - 1) continue;
        ret = min(dist(P[idx], P[n_idx]) + recur(n_idx, jump - j), ret);
    }

    return ret;
}

int sol() {
    if (n == 0) return 0;

    P.resize(n);
    D.assign(n, vi(k + 1, inf));
    for (int i = 0; i < n; i++)
        cin >> P[i].x >> P[i].y;

    return recur(0, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int T; cin >> T;
    
    /*Get_Answer*/
    for (int t = 1; t <= T; t++) {
        cin >> n >> k;
        cout << "#" << t << " " << sol() << '\n';
    }
    
    return 0;
}




#include <bits/stdc++.h>
using namespace std;
 
const int N = 500;
int x[N], y[N];
int dp[N][N];
char buf[131072];
 
inline int d (int i, int j) {
    return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}
 
 
int main() {
    setvbuf(stdin, buf, _IOFBF, 131072);
    int tc;
    scanf("%d", &tc);
    for (int ti=1; ti<=tc; ++ti) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i=0; i<n; ++i) {
            scanf("%d%d", x+i, y+i);
        }
        for (int v=1; v<n; ++v) {
            for (int ki=0; ki<=min(v-1,k); ++ki) {
                if (ki == v-1) {
                    dp[v][v-1] = d(0, v);
                    continue;
                }
                int cur = numeric_limits<int>::max();
                for (int i=0; ki-i>=0; ++i) {
                    cur = min(cur, dp[v-i-1][ki-i]+d(v-i-1, v));
                }
                dp[v][ki] = cur;
            }
        }
        printf("#%d %d\n", ti, dp[n-1][k]);
    }
}
