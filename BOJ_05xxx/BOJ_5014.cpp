// [Tag]
// #lev2 #BFS #아이디어

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
using namespace std;

#define fi      first    
#define se      second  
/** Type Define **/
typedef long long int           ll;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<bool>            vb;
typedef vector<string>          vs;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;

constexpr int               inf = 2123456789;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;

template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T, vector<T>, greater<T> >;


template<class T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i + 1 < vec.size())os << ' ';
    }
    return os;
}
template<class T>
istream& operator >> (istream& is, vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++)is >> vec[i];
    return is;
}


/*************************************************/
int F, S, G,U,D;    //  maxFloor StartPoint Goal Up Down
vb chk;             // i층을 확인했으면 chk[i] == true;

void sol() {
    int ans(0);
    chk.assign(F + 1, false);
    chk[S] = 1;
    queue<pii> Q; // pii { 현재검사하는 층, 최소도달버튼 }
    Q.push({ S, 0 });

    while (!Q.empty()) {
        pii q = Q.front();
        Q.pop();
        //cout << "q : " << q.fi << "  idx:" << q.se << endl;
        if (q.fi == G) {
            cout << q.se << '\n';
            return;
        }
        int u = q.fi + U;
        int d = q.fi - D;

        if (u <= F && !chk[u]) {
            chk[u] = 1;
            Q.push({ u, q.se + 1 });
        }
            
        if (d >= 1 && !chk[d] ) {
            chk[d] = 1;
            Q.push({ d, q.se + 1 });
        }

    }
    cout << "use the stairs" << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    /*INPUT*/
    cin >> F >> S >> G >> U >> D;

    /*Get_Answer*/
    sol();
    
    return 0;
}
