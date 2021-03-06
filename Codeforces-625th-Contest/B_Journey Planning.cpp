/* #lev3 #Hash                          */

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

#define all(x)  x.begin(), x.end()
#define pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/

int n;
vl bp, bn;
ll mx(-1);

void MX(ll& a, const ll& y){
    if(a < y) a = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    cin >> n;
    bp.resize( 400005, 0);
    bn.resize(400005, 0);
    for(int i=1; i<=n;i++){
        ll x;
        cin >> x;
        x -= i;
        if(x >= 0)  bp[x] += (x + i);
        else        bn[-x] += (x + i);
        if (x >= 0) MX(mx, bp[x]);
        else        MX(mx, bn[-x]);
    }
    cout << mx << endl;
    return 0;
}
