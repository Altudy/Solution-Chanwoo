/* #lev2 #2Pointer */

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
string s;
struct node {
    node() {
        e[1] = 0;
        e[2] = 0;
        e[3] = 0;
    }
    node(int a, int b, int c) {
        e[1] = a;
        e[2] = b;
        e[3] = c;
    }
    
    /*
    node(int x){
        if (x == 1)     e[1]++;
        else if (x == 2)   e[2]++;
        else if (x == 3)   e[3]++;
    }*/
    int e[4];
};
int sol() 
{
    cin >> s;
    int n = s.length();
    //int a[4]{};
    //vector<node> nodes(n, node());
    //for (int i = 0; i < n; i++) {
    //    int x = s[i] - '0';
    //    a[x]++;
    //    nodes[i] = node(a[1], a[2], a[3]);
    //}

    int b[4]{};
    int ans(inf);
    for (int i = 0, j = 0; i < n; i++) {
        int x = s[i] - '0';
        b[x]++;
        if (b[1] && b[2] && b[3]) {
            int y = s[j++] - '0';
            b[y]--;
            while (b[y] > 0) {
                y = s[j++] - '0';
                b[y]--;
            }
            ans = min(ans, b[1] + b[2] + b[3] + 1);
        }
        else { //최소 1개씩을 못찾은경우
            continue;
        }
    }
    if (ans == inf) return 0;
    return ans;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    uint t; cin >> t;
    while(t--)
        cout << sol() << '\n';

    return 0;
}
