/* #lev2 #Math                          */

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

}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    
    /*  [al, ar]은 0.08이자가 a가 나오는 구간, 
        [bl, br]은 0.1이자가 b가 나오는 닫힌 구간이다.*/
        
    int al = a * 12 + (a + 1) / 2; a++; //올림 처리
    int ar = a * 12 + (a - 1) / 2; a--; //내림 처리
    int bl = b * 10; b++;
    int br = b * 10; b--; br--;
    
    
    //겹치는 부분이 없다면 -1 출력.
    if (ar < bl || al > br) cout << "-1\n";
    else {
        int cl = max(al, bl);
        int cr = min(ar, br);
        if (cl <= cr) cout << cl << endl;
        else cout << "-1\n";
    }


    return 0;
}
