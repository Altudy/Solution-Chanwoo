/* #lev2 #구현          */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include <map>
#include <iomanip>
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

int N, M;

void sol() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    cin >> N >> M;
    vi num(N, -1);
    bool chk(false);

    for (int i = 0; i < M; i++) {
        int s, c; cin >> s >> c;
        s--;
        if(num[s] >= 0)
            if (num[s] != c) { cout << "-1\n"; return 0; }
        num[s] = c;
    }
    if (num[0] == 0 && N > 1) {
        cout << "-1\n"; return 0;
    }
    if (num[0] == -1 && N > 1) num[0] = 1;

    string s;
    for (int i = 0; i < N; i++) {
        if (num[i] == -1) s += '0';
        else s += ( '0' + num[i]);
    }
    cout << s << endl;


    return 0;
}
