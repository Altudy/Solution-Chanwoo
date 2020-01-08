#include <iostream> // #lev1
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
 
    A -= K;
    if (A >= 0) {
        cout << A << " " << B << endl;
    }
    else {
        B += A;
        cout << 0 << " ";
        if (B >= 0)
            cout << B << endl;
        else
            cout << 0 << endl;
    }
 
 
    return 0;
}
