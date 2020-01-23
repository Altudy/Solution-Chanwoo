// [Tag]
// #lev2 #아이디어

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
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

constexpr int               inf =   	2123456789;
constexpr long long 		INF = 		9123456789123456789;
constexpr long long         MOD =       1000000007LL;

template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T,vector<T>,greater<T> >;



/*************************************************/
int Q, q, x;
vi arr;

void sol() {
    int MEX = 0;
    int needed = 0;

    for (int i = 0; i < Q; i++) {
        cin >> q;
        arr[q % x]++;
        while (arr[needed] != 0) {
            arr[needed]--;
            MEX++;
            needed = (needed + 1) % x;
        }
        cout << MEX << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    /*INPUT*/
    cin >> Q >> x;
    arr.assign(x, 0);

    /*Get_Answer*/
    sol();
    return 0;
}
