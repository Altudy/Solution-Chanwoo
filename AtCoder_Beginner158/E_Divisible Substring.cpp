/* #lev4 #Math #Greedy    */

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

int n, p;
string s;
vi cnt;

void sol() {
    ll ans = 0;
    int pow10 = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        char x = s[i] - '0';
        //1의 자리에서 부터 검사하며 p의 배수인지 검사하고 나머지가 같은 녀석들을 count한다.
        sum = (sum + x * pow10) % p;

        //같은 나머지가 나오게 했다는 말은 그 나머지가 나온 부분에 대해 현재 추가된 것이 3의 배수라는 말.
        ans += cnt[sum]++;
        pow10 = pow10 * 10 % p;
    }
    cout << ans <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    cin >> n >> p; 
    cnt.assign(p, 0); cnt[0] = 1;
    cin >> s;

    // 2 또는 5의 배수일땐 다르게 처리, 10이 divisible하므로 
    //현재 자리가 dibisible하면 모든 postfix에 대하여 True
    if (p == 2 || p == 5) {
        ll ans(0);
        int z = 0;
        for (int i = 0; i < n; i++) {
            char x = s[i] - '0';
            if (x % p == 0) ans += ((ll)i + 1);
        }
        cout << ans << endl;
        return 0;
    }
    else {
        reverse(s.begin(), s.end()); //1의 자리서부터 접근.
        sol();
    }

    return 0;
}
