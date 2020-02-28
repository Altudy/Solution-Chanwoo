// #lev4 #다이나믹 
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
template<class T>
void MN(T& a, T b) {
    if (a > b) a = b;
}
 
int main() {
    int i;
    int dp1 = 0;
    int dp2 = 1073709056;
    int nx1;
    int nx2;
 
    int N; string S;
    cin >> S;
    N = S.size();
    S = "0" + S;
 
    for (i = 0; i <= N; i++)
        S[i] -= '0';
 
    
    for (i = N; i >= 0; i--) {
        nx1 = nx2 = 1073709056;
        //다음 숫자에서 빌려오지 않음
        MN(nx1, dp1 + S[i]);
        MN(nx1, (dp2 + 1) + S[i]);
        //다음 숫자에서 10빌려옴
        MN(nx2, dp1 + 10 - S[i]);
        MN(nx2, dp2 + (10 - S[i]) - 1); //원래 현재에서 빌린 1을 하나 위에서 빌려오는 것으로 해결되므로 -1을 가중해준다.
 
        dp1 = nx1;
        dp2 = nx2;
    }
 
    cout << dp1 << '\n';
    return 0;
}
