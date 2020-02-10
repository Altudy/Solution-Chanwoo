/* #lev4 #다이나믹 #아이디어                      */
 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <cassert>
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
 
constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/
vvl dp0, dp1;
 
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
 
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
 
    dp0.assign(n+1, vl(k+1, 0)); // dp0[i][j] 가장 왼쪽에서부터 i개 골랐고, 
                                 // 그 중 j개의 Non-zero digit를 가지고 있으며, 
                                 // 아직 고르지 않는 오른쪽의 digit에 따라 허용되지 않을 수도 있는 숫자의 개수.
                                 // 예를 들어'10203'에서 dp[3][2]는 세자리 숫자중 102 하나가 해당하므로 1이다.
    
    dp1.assign(n+1, vl(k+1, 0)); // dp1[i][j] 가장 왼쪽에서부터 i개까지 고려할 때,
                                 // 그 중 j개의 Non-zero digit를 가지고 있는 숫자 중 나머지 숫자를 고르는 것과 
                                 // 상관없이 무조건 합당한 숫자의 개수
                                 // 예를 들어 '10203'에서 dp1[2][1]은 '01 ~ 09'까지 9개이다. '10'은 오른쪽에 3이상이 나올 경우 해당되지 않으므로 
                                 // dp0[2][1] = 1로 가지고 있는다.
    
    //중요한 초기값, 0개 사이즈에서 0개 고르는 선택도 뒤에 따라서 안될 수 있는 조합이 1개라고 가정.
    //dp[1][1] = 0 임도 중요.
    dp0[0][0] = 1;
    
    //index i로부터  size i+1개를 채웠을 때를 구해나감.
    for(int i=0; i<n;i++)       
        // 0개 집을 때부터 k개 집을때까지 차례로 DP로 구해나감.
        for (int j = 0; j <= k; j++) {
            dp1[i + 1][j] += dp1[i][j]; //j나
            if (s[i] == '0') dp0[i + 1][j] += dp0[i][j]; //만약 s[i]가 '0'이면,  dp0[i+1][j] == dp0[i][j]이게 된다.
            else             dp1[i + 1][j] += dp0[i][j]; //만약 s[i]가 '0'보다 크다면, i+1번째로 0인 경우에, dp1[i+1][j]에 dp0[i][j]가 포함되게 된다.
            
            //s[i]가 '0'인 경우에 대한 예외처리는 끝났고, 1~9사이인 경우에 대해 dp[i+1][j+1]을 채운다.
            for (char ch = '1'; ch <= '9'; ch++) {
                if (j + 1 <= k && s[i] == ch) dp0[i + 1][j + 1] += dp0[i][j];
                if (j + 1 <= k) {
                    //i까지 고른 숫자들이 s보다 작은 경우에 대해, dp[i][j]가 i+1번째로 1~9인 각 경우에 모두 성립하므로 9번 더해준다.
                    dp1[i + 1][j + 1] += dp1[i][j];
                    //i까지 고른 숫자들이 s와 같은 경우 i+1번째로 고른 숫자가 s[i]보다 작아야 항상 성립하는 dp1[i+1][j+1]의 경우에 맞다.
                    //그러므로 s[i]가 3이라 하면 1, 2의 경우에 대해서만 dp0[i][j]를 더해준다. s문자열에서 i번째까지 j개의 숫자가 있으면 1일 것이고, 
                    // 그보다 적거나 많으면 오른쪽을 보지 않아도 가능/불가능을 가를 수 있으므로 0일 것이다.
                    if (ch < s[i])
                        dp1[i + 1][j + 1] += dp0[i][j];
                }
            }
        }
        
    ll ans = dp0[n][k] + dp1[n][k];
    cout << ans << endl;
    return 0;
}
