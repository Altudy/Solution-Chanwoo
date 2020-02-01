/* #lev3 #DP #아이디어                     */

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


constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/
int H, N;
vi dp;

void Min(int& x, int y) { //no return
    if (x > y)
        x = y;
}

void sol() {
    for (int i = 0; i < N; i++) {
        int a, b; // a: damage, b: cost.
        // 0 ~ H까지 소모되는 cost를 최소로 계속 업데이트.
        cin >> a >> b;
        for (int i = 0; i < a; i++)
            Min(dp[i], b);
        for (int i = a; i <= H; i++)
            Min(dp[i], dp[i - a] + b); //0부터 업데이트해서 올라오므로 dp[i-a]는 a,b에 있어서 최적을 보장.
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    //cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> H >> N;
    // dp를 H + 1로 사이즈를 잡았었는데, 
    // 입력으로 주어지는 A가 H보다 큰 경우가 있었어서 최대로 잡아주었어야 했다.
    dp.assign(10001, INT32_MAX); 

    dp[0] = 0; //동적계획법이므로 초기값에 신경을 써주자.

    sol();
    cout << dp[H] << '\n';

    return 0;
}
