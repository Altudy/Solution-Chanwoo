//#lev1
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
 
constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/

/* A */
int main(){
  int H, A;
  cin >> H >> A;
  
  int ans = H/ A;
  if(H % A != 0) ans ++;
  cout << ans << endl;
  
  
  return 0;
}


/* B */
int N, H;
vi A;
void sol() {
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> H >> N;
    int sum(0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    if (sum < H) cout << "No\n";
    else cout << "Yes\n";
 
    return 0;
}

/* C */
int N, K;
vi H;
void sol() {
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> N >> K;
    H.resize(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    if (N <= K) cout << "0\n";
    else {
        ll sum(0);
        sort(H.begin(), H.end());
        for (int i = 0; i < (N - K); i++) {
            sum += (ll)H[i];
        }
        cout << sum << '\n';
    }
    
 
    return 0;
}

/* D */
ll H;
 
ll sol(ll H) {
    int exp(0);
    while (H > 1) {
        H /= 2;
        exp++;
    }
    ll sum(0); ll e(1);
    for (int i = 0; i <= exp; i++) {
        sum += e;
        e *= 2;
    }
    return sum;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> H;
    cout << sol(H) << endl;
 
    return 0;
}
