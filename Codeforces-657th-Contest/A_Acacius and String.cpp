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
#include <numeric>
//#pragma warning(disable:4996)

using namespace std;


/** Type Define **/
typedef unsigned int            uint;
typedef unsigned char           uchar;
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

string s, ans = "abacaba";
int n, len;

int count(const string& str) {
    int cnt(0);

    for (int i = 0; i <= len - 7; i++) {
        if (str.substr(i, 7) == ans) cnt++;
    }

    return cnt;
}

void sol() {
    cin >> n;
    cin >> s;

    len = s.length();
    int idx(-1);
    int cnt = count(s);

    if (cnt > 1) {
        cout << "No\n";
        return;
    }

    if (cnt == 1) {
        cout << "Yes\n";
        for (int i = 0; i < len; i++) 
        {
            if (s[i] == '?') cout << 'd';
            else cout << s[i];
        }   cout << '\n';
        return;
    }

    bool flag1(1);     // Check whether 'ans' was found or not.
    bool flag2(0);     // Check whether temp has only one 'ans'.

    for (int i = 0; i <= len - 7; i++) {
        string temp = s;

        
        flag1 = true;

        for (int j = i; j < i + 7; j++) 
        {
            if (temp[j] == ans[j - i]) continue;
            else if (temp[j] == '?') temp[j] = ans[j - i];
            else
            {
                flag1 = false;
                break;
            }
        }

        
        flag2 = false;

        if (flag1) 
        {
            if (count(temp) == 1) 
            {
                flag2 = true;
                s = temp;
                break;
            }
        }
    }

    if (flag2) 
    {
        cout << "Yes\n";
        for (int i = 0; i < len; i++) {
            if (s[i] == '?')
                cout << 'd';
            else
                cout << s[i];
        }   cout << '\n';
    }
    else 
    {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--)
        sol();
    

    return 0;
}
