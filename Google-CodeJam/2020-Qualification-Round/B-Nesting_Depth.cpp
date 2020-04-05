/* #lev2 #구현 */

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
    s = '0' + s;

    for (char dig = '1'; dig <= '9'; dig++) {
        string sn;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] >= dig) {
                int a = i, cnt(0);
                while (i < n && s[i] >= dig) cnt++, i++;
                sn += ( '(' + s.substr(a, cnt) + ')');
                if (i < n) sn += s[i];
            }
            else
                sn += s[i];
        }
        s = sn;
    }
    for (int i = 1; i < s.size(); i++) cout << s[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        sol();
        cout << '\n';
    }

    return 0;
}
