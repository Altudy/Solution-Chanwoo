/* #lev3 #constructive  */

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

template<typename T>
constexpr auto all(T x) { return x.begin(), x.end(); }
constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/

int q, l, r;
string s;
vi max_r;
int alpha[26]{};

int toNum(char ch) {
    return ch - 'a';
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> s >> q;
    int n = s.size();
    int cnt(0); // distinct alphabet count;
    int r(-1);  // maximum r for each max_r[l] that has maximum two distinct alphbet in range[l, r].
    max_r.resize(n);
    for (int i = 0; i < n; i++) {
        //when l is i.
        while (r + 1 < n) {
            int x = toNum(s[r + 1]);
            if (alpha[x] == 0) {
                if (cnt + 1 <= 2) {
                    alpha[x]++;
                    cnt++;
                    r++;
                }
                else break;
                
            }
            else {
                alpha[x]++;
                r++;
            }
        }
        max_r[i] = r;
        //cout << "for " << i + 1 << "max r : " << r + 1 << endl;
        int x = toNum(s[i]);
        alpha[x]--;
        if (alpha[x] == 0) cnt--;
    }

    while (q--) {
        cin >> l >> r;
        l--, r--;
        if (l != r && s[l] == s[r] && max_r[l] >= r) cout << "No\n";
        else cout << "Yes\n";
    }
    

    return 0;
}
