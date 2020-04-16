/* #lev3 #BFS */

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
int n, m, food;
vector<vch> M;
vvi D; // Map, Distance
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
struct C { //coord
    int r, c, d;
};

bool check(const C& co) {
    if (co.r >= 0 && co.r < n && co.c >= 0 && co.c < m) {
        if (D[co.r][co.c] < 0 && M[co.r][co.c] != 1)
            return true;
    }
    
    return false;
}

void BFS(const C& co) {
    queue<C> Q;
    Q.push(co);
    while (!Q.empty()) {
        C q = Q.front(); Q.pop();
        int r(q.r), c(q.c), d(q.d);
        
        if (D[r][c] > 0) continue;
        D[r][c] = d;

        if (M[r][c] > 2) {
            food = d; break;
        }

        for(int i=0; i<4;i++){
            C next = { r + dr[i], c + dc[i], d + 1 };
            if (check(next)) Q.push(next);
        }

        d++;
    }
}

void sol() {
    cin >> n >> m;
    food = -1;
    M.assign(n, vch(m, 0));
    D.assign(n, vi(m, -1));
    C start;

    for(int i=0; i<n;i++)
        for (int j = 0; j < m; j++) {
            char x; cin >> x; 
            x -= '0';

            M[i][j] = x;
            if (x == 2) start = { i, j, 0 };
        }

    BFS(start);
    if (food >= 0) cout << "TAK\n" << food << '\n';
    else cout << "NIE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    sol();


    return 0;
}
