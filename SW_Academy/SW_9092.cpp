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



#include <cstdio>
#include <cmath>
#include <cstdint>
#include <algorithm>
//#pragma warning(disable:4996)
using namespace std;

const int N = 500;
int x[N], y[N];
int DP[N][N];
char buf[131072];

inline int dist(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}


int main() {
    setvbuf(stdin, buf, _IOFBF, 131072);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", x + i, y + i);
        }
        //solve
        for (int v = 1; v < n; ++v) { //vertex : ~v까지의 거리
            for (int ki = 0; ki <= min(v - 1, k); ++ki) { // 최대 ki만큼 건너뛰었을 때의 DP
                if (ki == v - 1) {
                    DP[v][v - 1] = dist(0, v);
                    continue;
                }
                int mn = INT32_MAX;
                for (int i = 0; i <= ki; ++i) //v-1 ~ v 부분을 건너뛰는 경우를 고려하여 최솟값 탐색. 
                    mn = min(mn, DP[v - i - 1][ki - i] + dist(v - i - 1, v));
                
                DP[v][ki] = mn;
            }
        }
        printf("#%d %d\n", t, DP[n - 1][k]);
    }
}
