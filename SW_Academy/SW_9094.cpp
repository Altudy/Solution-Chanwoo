// [Tag]
// #lev3 #시간줄이기 #BFS

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
int N;
int sol() {
    vector<vi> ori(N, vi(N, false));
    vector<int> visited(N);

    for (int i = 0; i < N; i++) {
        int kn, j; cin >> kn;
        while (kn--) {
            cin >> j;
            ori[i][j - 1] = true;
        }
    }

    //for (int i = 0; i < N; i++)
    //    for (int j = 0; j < N; j++)
    //        if (ori[i][j]) cout << i + 1 << " to " << j + 1 << '\n';
    int mn(inf);
    
    
    for (int R = 0; R < N; R++) {  //Root직원 기준 int R = 0; R < N; R++
        int cnt(1);
        int ans(0);
        queue<int> Q;
        for (auto &v : visited) v = false;
        Q.push(R);
        while (!Q.empty()) {
            int cnt_size = Q.size();
            ans += (cnt * cnt_size);
            if (ans > mn) break;

            while (cnt_size--) {
                int q = Q.front(); Q.pop();
                visited[q] = true;
                for (int i = 0; i < N; i++)
                    if (ori[i][q] && !visited[i]) Q.push(i), visited[i] = true;
                
            }
            cnt++;
        }

        if (mn >= ans) mn = ans;
    }
    return mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int T; cin >> T;
    /*INPUT*/
    for (int t = 1; t <= T; t++) {
        cin >> N;
        cout << "#" << t << " " << sol() << '\n';
    }
    
    return 0;
}


