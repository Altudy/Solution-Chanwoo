/* #lev4 #그리디 #DP #아이디어   */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
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
constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/
int n, d, a;
ll ans(0);
vector<pll> M; //monster {location, health}.
vl D;


int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> n >> d >> a;
    for (int i = 0; i < n; i++) {
        int x, h;
        cin >> x >> h;
        int bomb = h / a + (h % a != 0); //calculate needed bomb.
        M.push_back({ x, bomb });
    }
    sort(all(M));

    D.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (D[i] < M[i].second) { //아직 i번째 위치에서 충분히 bomb이 들어가지 않았다면,
            ll rest = M[i].second - D[i]; //rest만큼 추가.
            ll bound = M[i].first + 2 * d;

            ans += rest;
            D[i] += rest;
            
            int p = upper_bound(all(M), pll{ bound, INF }) - M.begin(); 
            //영향 받는 범위 +2d 다음에 -=rest.
            D[p] -= rest;
        }
        // 다음 D원소가 -=rest가 쌓여있으면 상쇄될것이므로 
        // DP로 다음 지점에 데미지를 축적한다.
        D[i + 1] += D[i]; 
    }

    cout << ans << endl;

    return 0;
}


