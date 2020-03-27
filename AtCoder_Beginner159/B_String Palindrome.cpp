/* #lev1 #문자열처리                          */

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

void sol() {
    string s; cin >> s;
    int n = s.length();
    int half = (n + 1) / 2; 
    // 짝수개일 경우 반보다 하나 더 검사하긴 하겠지만,
    // 답은 구할 수 있다.


    for (int i = 0; i < half; i++)
        if (s[i] != s[n - 1 - i]) {
            cout << "No\n"; return;
        }

    int k = n/2;
    for (int i = 0; i < k; i++)
        if (s[i] != s[k - 1 - i] || 
            s[k+i+1] != s[n-1-i] ) {
            cout << "No\n"; return;
        }

    cout <<"Yes\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    int T(1);
    while (T--)
        sol();

    return 0;
}
