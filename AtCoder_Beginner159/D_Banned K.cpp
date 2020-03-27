/* #                          */

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
    int n; cin >> n;
    vi input(n);
    vi num(n + 1, 0);
    vl same(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        num[input[i]]++;
    }

    ll sum(0);
    for (int i = 1; i <= n; i++)
        if (num[i] > 0) {
            ll x = ll(num[i]);
            same[i] = x * (x - 1) / 2LL;
            sum += same[i];
        }

    for (int i = 0; i < n; i++) {
        int x = input[i];
        ll newSum = sum - same[x];
        ll newNum = num[x] - 1;
        newSum += newNum * (newNum - 1) / 2;
        cout << newSum << '\n';
    }

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
