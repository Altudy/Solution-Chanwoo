#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
 
#define Inf             987654321
using namespace std;
 
typedef long long int   ll;
typedef pair<ll, ll>    pii;
typedef vector<ll>      vi;
typedef vector<vi>      vii;
typedef vector <vector<char> > vvc;
typedef vector <char> vc;
/*************************************************/
 
ll N, K, R, S, P, ans;
string T;
 
void sol() {
    for (ll i = 0; i < N; i++) {
        if (i >= K) {
            if (T[i] == T[i - K]) {
                T[i] = 'x';     //중복이므로 continue,
                continue;       //하지만 다음 K번째에는 영향을 주면 안되므로 'x'로 처리한다.
            }                   //가위바위보라서 선택지가 이기는것말고 2개이기 때문에 가능한 경우.
        }
        if (T[i] == 'r') ans += P;
        else if (T[i] == 's') ans += R;
        else if (T[i] == 'p') ans += S;
        else;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> N >> K >> R >> S >> P >> T;
    sol();
    cout << ans;
    return 0;
}

//#lev2 #중복처리
