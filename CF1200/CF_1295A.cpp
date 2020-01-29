/* #lev1 #이상한..                          */

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

constexpr int               inf =   	0x3f3f3f3f;
constexpr long long 		INF = 		9123456789123456789;
constexpr long long         MOD =       1000000007LL;
/*************************************************/

void solve()
{
    int n;
    cin>>n;
    if (n&1) {cout<<7; n-=3;} //첫자리는 홀수면 7로 채우는게 유리.
    while (n)
    {
        cout<<1; n-=2; //그냥 하나씩 해도 시간차이 별로 안나는..
    }
    cout<<endl;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int t;
    cin>>t;
    while (t--) solve();
 
 
 
}
