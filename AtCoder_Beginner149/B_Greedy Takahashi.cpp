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
/*************************************************/
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    ll A, B, K;
    cin >> A >> B >> K;
 
    A -= K;         // A는 쿠키를 K번 집어먹는다.
    if (A >= 0) {   // 만약 A가 K개이상의 쿠키를 가지고 있었다면, 남은 A와 B의 쿠키를 출력.
        cout << A << " " << B << endl;
    }
    else {          // 그렇지 않으면 A는 이제 음수, 음수의 절댓값만큼 B의 쿠키를 먹는다.
        B += A;
        cout << 0 << " "; //A의 쿠키 출력.
        if (B >= 0)       //B가 충분한 쿠키를 가지고 있었으면 남은 B를 출력, 아니면 다 먹었으므로 0
            cout << B << endl;
        else
            cout << 0 << endl;
    }
 
 
    return 0;
}

//#lev1 
