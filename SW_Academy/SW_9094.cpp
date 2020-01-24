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

typedef struct employee {
    employee() { visit = false;}
    bool visit;
    vi from;
}E;

int N;

ll sol() {
    vector<E> Es(N, E());
    ll mn(INF);

    for (int i = 0; i < N; i++) {
        int kn, j; cin >> kn;
        while (kn--) {
            cin >> j;
            Es[j - 1].from.push_back(i);
        }
    }
    
    for (int R = 0; R < N; R++) { // check all case.

        ll val(1), ans(0);  // 1 layer's value & temp answer
        int emplo_size(1);  // The number of employee in root tree
        for(auto &E: Es) E.visit = false;  //initialize
        queue<E*> Q;        //we'll use Queue for BFS

        Q.push(&Es[R]);     // At first, do Root case.
        Es[R].visit = true;

        while (!Q.empty()) {
            ll Q_size = (ll) Q.size();
            ans += (val * Q_size);
            if (ans > mn) break;

            while (Q_size--) {
                E* q = Q.front(); Q.pop();
                for (auto f : q->from)
                    if (Es[f].visit == false) { // put employee in tree.
                        emplo_size++;  Q.push(&Es[f]);
                        Es[f].visit = true;
                    }
            }
            val++;
        }

        // If all employee place in tree && find optimal answer, Update.
        if (emplo_size == N && mn >= ans) mn = ans;
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





