// [Tag]
// #lev1 #구현

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
#pragma warning(disable:4996)

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

constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;

template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T, vector<T>, greater<T> >;

/*************************************************/
char buf[131072];
int N;
vi book;
vb chk;

int main() {
    setvbuf(stdin, buf, _IOFBF, 131072);
    //int T; scanf("%d", &T);
    scanf("%d", &N);
    //int T; cin >> T;
    book.resize(N); chk.assign(N + 1, false);
    for (int i = 0; i < N; i++)
        scanf("%d", &book[i]);
    int ans(0);
    int lo(0), hi(N), now(N);
    while (lo != hi) {
        int mx(0);
        for (int i = hi - 1; i >= lo; i--) {
            if (book[i] == now) {
                chk[now] = true;
                hi = i; break;
            }
            chk[book[i]] = true; ans++;
            if (mx < book[i]) mx = book[i];
        }

        while (mx != 0 && lo != hi) {
            if (book[lo] > mx) 
                break;
            else    
                chk[lo] = true; ans++;
            lo++;   
        }
        while (chk[now] && now >= 1) now--;
    }
    /* SOLVE */

    printf("%d", ans);

    return 0;
}
