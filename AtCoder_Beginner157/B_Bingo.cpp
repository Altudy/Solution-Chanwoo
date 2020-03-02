/* #lev1 #Hash                          */

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
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/
void sol() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    int Bo[3][3];
    int* wh[101];
    for (int i = 0; i < 101; i++) wh[i] = new int(-1);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cin >> Bo[i][j];
            wh[Bo[i][j]] = &Bo[i][j];
        }

    int n; cin >> n;
    vi b(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int d = *wh[x];
        if (d > 0) (*wh[x]) = 0;
    }

    bool ans(false);
    for (int i = 0; i < 3; i++)
        if (Bo[i][0] + Bo[i][1] + Bo[i][2] == 0) ans = true;
    for (int i = 0; i < 3; i++)
        if (Bo[0][i] + Bo[1][i] + Bo[2][i] == 0) ans = true;
    if (Bo[0][0] + Bo[1][1] + Bo[2][2] == 0) ans = true;
    if (Bo[0][2] + Bo[1][1] + Bo[2][0] == 0) ans = true;
 
    if (ans) cout << "Yes\n";
    else cout << "No\n";

    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++)
    //        cout << Bo[i][j] << " ";
    //    cout << endl;
    //} cout << endl;

    return 0;
}
