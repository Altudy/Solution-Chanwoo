// [Tag]
// #lev2 #플로이드

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
using namespace std;

#define fi     	first    
#define se     	second  

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

vvl D;
int V, E;


ll sol() {
    
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++)
                if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
        }
    }

    ll mn((ll) inf);
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            if (i == j) continue;
            else {
                if (D[i][j] + D[j][i] < mn)
                    mn = D[i][j] + D[j][i];
            }
    if (mn < inf)
        return mn;
    else return -1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    /*INPUT*/
    cin >> V >> E;
    D.assign(V + 1, vl(V + 1, inf));
    for (int i = 1; i <= V; i++)
        D[i][i] = 0;

    ll a, b, c;
    for (int i = 1; i <= E; i++) {
        cin >> a >> b >> c;
        D[a][b] = c;
    }

    /*Get_Answer*/
    cout << sol() << endl;
    
    return 0;
}

