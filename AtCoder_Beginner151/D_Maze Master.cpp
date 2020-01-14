// [Tag]
// #lev3 #BFS #queue

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
using namespace std;

/** Type Define **/
typedef long long int           ll;
typedef pair<ll, ll>            p_ll;
typedef vector<string>          vs;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;

constexpr int               INF = 1001001001;
constexpr long long         MOD = 1000000007LL;
/*************************************************/
int H, W;   //Height, Width
vs M;       //Map

int dh[4] = { 1, -1,  0,  0 };
int dw[4] = { 0,  0,  1, -1 };

int BFS(int h, int w) {
    queue <pair <int, int>> Q;    // 검사할 좌표를 Breath-first로 저장.
    vvi dist(H, vi(W, INF));    // 들르지 않은 좌표는 INF, BFS라서 최초 저장되는 값이 최소이므로 두번 비교필요없음.
    Q.push({ h, w });
    dist[h][w] = 0;
    int mx_dist(0);

    while (!Q.empty()) {
        pair<int, int> P = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nh(P.first + dh[i]), nw(P.second + dw[i]);
            if (0 <= nh && nh < H && 0 <= nw && nw < W) {
                if (M[nh][nw] == '.' && dist[nh][nw] == INF) {
                    dist[nh][nw] = dist[P.first][P.second] + 1;
                    if (dist[nh][nw] > mx_dist)
                        mx_dist = dist[nh][nw]; // (h, w) 기준으로 제일 멀리 떨어져있는 좌표와의 길이 저장.
                    Q.push({ nh, nw });
                }
            }
        }
    }

    return mx_dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    /*INPUT*/
    cin >> H >> W; // distinquish each cells by 0..(H*W-1) number.
    M.resize(H);
    for (auto& m : M) cin >> m;


    int ans(0);
    for(int h=0; h<H; h++)
        for (int w = 0; w < W; w++)
            if (M[h][w] == '.') ans = max(ans, BFS(h, w)); //모든 road square에 대하여 비교.
        

    cout << ans << '\n';

    /*Get_Answer*/
    //sol();
    return 0;
}
