/* #Math #Geometry */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include <map>
#include <iomanip>
#include <functional>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <numeric>
//#pragma warning(disable:4996)

using namespace std;


/** Type Define **/
typedef unsigned int            uint;
typedef unsigned char           uchar;
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
// C1 n is even. C2 n is odd.
const double pi = std::acos(-1);

double sol() {
    int n; //even
    cin >> n; n *= 2;  // 2-n gon.
    double x = pi / (double)n;
    double side = 1 / tan(x);
    return side;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    uint t; cin >> t;
    while(t--)
        cout << sol() << '\n';

    return 0;
}
