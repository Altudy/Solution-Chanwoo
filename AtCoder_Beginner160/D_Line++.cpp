/* #lev2 #Greedy */
/* W를 굳이 선언하지 않아도 되지만, 더 General한 적용이 가능 */

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
int n, x, y;
vvi W; 
vi ans;
void sol() {
    cin >> n >> x >> y;
    W.assign(n + 1, vi(n + 1, 0));
    ans.assign(n, 0);

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            W[i][j] = (W[j][i] = j - i);
        

    W[x][y] = (W[y][x] = 1);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (W[i][j] > (W[i][x] + 1 + W[y][j]))
                W[i][j] = W[j][i] = (W[i][x] + 1 + W[y][j]);
            ans[W[i][j]]++;
        }

    for (int i = 1; i < n; i++)
        cout << ans[i] << '\n';
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
