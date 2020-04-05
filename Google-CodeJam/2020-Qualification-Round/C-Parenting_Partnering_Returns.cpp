/* #lev2 #Greedy */

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

struct act {
    int s, e, th;
};

bool comp(act& a, act& b) {
    if (a.s != b.s)
        return (a.s < b.s);
    else
        return (a.e < b.e);
}

void sol() {
    int n; cin >> n;
    vector<act> acts(n);
    for (int i = 0; i < n; i++) {
        cin >> acts[i].s >> acts[i].e;
        acts[i].th = i + 1;
    }
    sort(acts.begin(), acts.end(), comp);
    //for (auto& x : acts)
    //    cout << x.s << ' ' << x.e << ' ' << x.th << '\n';
    vch ord(n + 1);
    int Cs(0), Ce(-1), Js(0), Je(-1);
    for (int i = 0; i < n; i++) {
        int s = acts[i].s, e = acts[i].e - 1;
        int th = acts[i].th;
        if (s > Ce) {
            Cs = s; Ce = e;
            ord[th] = 'C';
        }
        else {
            if (s > Je) {
                Js = s; Je = e;
                ord[th] = 'J';
            }
            else {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ord[i];
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
