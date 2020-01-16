// [Tag]
// #lev1 #시간줄이기

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
using namespace std;

#define fir     first    
#define sec     second  
#define endl	'\n' 

/** Type Define **/
typedef long long int           ll;
typedef pair<ll, ll>            p_ll;
typedef vector<string>          vs;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;

constexpr int               inf = 2123456789;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;

/*************************************************/
int T;
ll N, A, B;
ll sol() {
    ll ans = (B - A) * (N - 2) + 1;
    if (B < A || ans < 0) return 0;
    else return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    /*INPUT*/
    cin >> T;

    /*Get_Answer*/
    for(int t=1; t<= T; t++) {
        cin >> N >> A >> B;
        cout << "#" << t << ' ';
        cout << sol() << '\n';
    }
    
    return 0;
}
