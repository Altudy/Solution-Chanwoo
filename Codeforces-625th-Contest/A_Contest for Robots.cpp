/* #lev2 #Greedy           */

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
vi a, b;

void sol() {
    vi aa, bb;
    for(int i=0; i<n;i++){
        if(a[i] == b[i]) continue;
        if(a[i] < b[i]) bb.push_back(i+1);
        else aa.push_back(i+1);
    }

    int an(aa.size()), bn(bb.size());
    if(an == 0 && bn >= 0) {  cout << "-1\n"; return;}

    int x(bn / an + 1);
    cout << x << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n), b.resize(n);
    for(int i=0; i<n;i++) cin >> a[i];
    for(int i=0; i<n;i++) cin >> b[i];
    sol();
    return 0;
}
