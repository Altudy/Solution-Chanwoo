// [Tag]
// #lev2 #BFS

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

/*************************************************/

typedef struct board {
    board() { type = 0; rock = inf; }
    board(int t) { type = t; rock = inf; }
    int rock;   // how many walls should be broken
    //int dist;   //distance (not needed)
    int type;   // 0 : road, 1 : wall
}B;

int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<B>> Bo;

bool chk_range(int r, int c) {
    return (c >= 0 && c < N && r >= 0 && r < M);
}
int BFS() {
    queue<pii> Q;
    Bo[0][0].rock = 0;
    Bo[0][0].type = 0;
    Q.push({ 0, 0 });

    while (!Q.empty()) {
        pii p = Q.front(); Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (chk_range(nx, ny))
                if (Bo[nx][ny].rock > Bo[p.first][p.second].rock + Bo[nx][ny].type) {
                    Bo[nx][ny].rock = Bo[p.first][p.second].rock + Bo[nx][ny].type;
                    //cout << "(" << nx << "," << ny << ") : " << Bo[nx][ny].rock << endl;
                    Q.push({ nx, ny });
                }
        }
    }

    return Bo[M - 1][N - 1].rock;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    /*INPUT*/
    cin >> N >> M;
    Bo.resize(M, vector<B>(N));
    for(int i=0; i<M;i++) // row
        for (int j = 0; j < N; j++) { //col
            char a; cin >> a;
            Bo[i][j] = B(a - '0');
        }

    cout << BFS() << '\n';
    return 0;
}


