/* #lev3 #브루트포스 #Math    */

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
int a, b, c, A, B, C;

void get_k(int& i, int& j, int& k){
    if (j <= c) {
        if (c % j < (j - c % j)) {
            k = c - c % j;
        }
        else {
            k = c + (j - c % j);
        }
    }
    else {
        k = j;
    }
    
}

bool MN(int& x, int y) {
    if (x > y) {
        x = y; return true;
    }
    return false;
}

void sol() {    
    cin >> a >> b >> c;
    int mn(inf);
    for (int i = 1; i <= 10000; i++) {
        for (int j = i; j <= 20000; j += i) {
            int k; get_k(i, j, k);
            int cost = abs(a - i) + abs(b - j) + abs(c - k);
            if (MN(mn, cost)) {
                A = i, B = j, C = k;
            }
        }
    }

    cout << mn << '\n'
        << A << " " << B << " " << C << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    int T; cin >> T;

    while (T--)
        sol();

    return 0;
}
