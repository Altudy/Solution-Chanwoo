/* #lev2 #큐 #구현   */

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

ll sol() {
    int n, m;
    ll ans(0);
    cin >> n >> m;
    vl r(n), w(m);
    vi p(m);
    for (int i = 0; i < n; i++)
        cin >> r[i];
    for (int i = 0; i < m; i++)
        cin >> w[i];

    m *= 2;
    int in(0);
    queue<int> q;
    priority_queue<int, vi, greater<int>> pq;
    for (int i = 0; i < n; i++) pq.push(i);

    for (int i = 0; i < m; i++) {
        int x; cin >> x;

        if (x > 0) {
            x--;
            if (in < n) {
                in++;
                int idx = pq.top(); pq.pop();
                p[x] = idx; ans += (r[idx] * w[x]);
                //cout << "in : " << x + 1 << endl;
            }
            else {
                q.push(x);
            }
        }
        else {
            x *= (-1); x--;
            pq.push(p[x]); in--;
            //cout << "out : " << x + 1 << endl;
            if (!q.empty()) {
                x = q.front(); q.pop();
                in++;
                int idx = pq.top(); pq.pop();
                p[x] = idx; ans += r[idx] * w[x];
                //cout << "in : " << x + 1 << endl;
            }
        }
    }
    return ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "#" << t << " ";
        cout << sol() << '\n';
    }

    return 0;
}
