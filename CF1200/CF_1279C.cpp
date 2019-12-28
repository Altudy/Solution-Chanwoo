#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

#define Inf             987654321
#define syn             ios::sync_with_stdio(false);cin.tie();cout.tie();
using namespace std;

typedef long long int   ll;
typedef pair<ll, ll>    pii;
typedef vector<ll>      vi;
typedef vector<vi>      vii;
/****************************************************/
//CODE START

ll n, m;
ll where[100001];

void sol() {
    ll a, b;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        where[a] = i;
    }

    ll ans = 0; // 최종 답
    ll mx = -1; // 최고로 내려간 깊이.

    for (int i = 1; i <= m; i++) {
        cin >> b;
        // 만약 b로 받은 물건의 위치가 mx보다 위에 있으면 
        //'1'만에 가져갈수 있도록 분명 정렬되어 있을 것이다.
        if (where[b] < mx) ans++;
        else {
            mx = where[b];
            ans += (2 * (where[b] - i) + 1);
        }
    }
    cout << ans << endl;
}


int main() {
    syn;
    ll t;
    cin >> t;
    while (t--) {
        sol();
    }

    return 0;
}
