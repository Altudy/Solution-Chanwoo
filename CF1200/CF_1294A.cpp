// [Tag]
// #lev1

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

constexpr int               inf =   	2123456789;
constexpr long long 		INF = 		9123456789123456789;
constexpr long long         MOD =       1000000007LL;

/*************************************************/

int T;
ll a, b, c, n;
bool sol() {
    ll sum = a + b + c + n;
    if (sum % 3 != 0)
        return false;
    else {
        ll avg = sum / 3;
        if (a > avg || b > avg || c > avg)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    /*INPUT*/
    cin >> T;
    
    /*Get_Answer*/
    while (T--) {
        cin >> a >> b >> c >> n;
        if (sol())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
