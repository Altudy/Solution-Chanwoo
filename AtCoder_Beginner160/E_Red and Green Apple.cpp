/* #lev3 #Greedy */

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
int x, y, a, b, c;
void sol() {
    cin >> x >> y >> a >> b >> c;
    vi A(a);
    vi B(b);
    vi C(c);
    for (auto& x : A)
        cin >> x;
    for (auto& x : B)
        cin >> x;
    for (auto& x : C)
        cin >> x;

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    //for (auto& x : A)
    //    cout << x << " ";
    //cout << '\n';
    //for (auto& x : B)
    //    cout << x << " ";
    //cout << '\n';
    //for (auto& x : C)
    //    cout << x << " ";

    int Aidx(x - 1), Bidx(y - 1);
    for (int i = 0; i < c; i++) {
        char op;
        if (Aidx < 0 && Bidx < 0) break;
        else if (Aidx < 0) op = 'B';
        else if (Bidx < 0) op = 'A';
        else {
            if (A[Aidx] > B[Bidx]) op = 'B';
            else op = 'A';
        }

        if (op == 'B') {
            if (B[Bidx] < C[i]) {
                B[Bidx] = C[i];
                Bidx--;
            }
            else break;
        }
        else {
            if (A[Aidx] < C[i]) {
                A[Aidx] = C[i];
                Aidx--;
            }
            else break;
        }
    }

    ll sum(0);
    for (int i = 0; i < x; i++) sum += A[i];
    for (int i = 0; i < y; i++) sum += B[i];
    cout << sum << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    int T(1);
    while (T--)
        sol();


    return 0;
}
