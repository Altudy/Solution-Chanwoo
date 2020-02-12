/* #lev2 #도형 #아이디어                          */

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

#define all(x)  x.begin(), x.end()
#define pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     mod = 1000000007LL;
/*************************************************/
template <class T, class F = multiplies<T>>
T power(T a, long long n, F op = multiplies<T>(), T e = { 1 }) {
    assert(n >= 0);
    T res = e;
    while (n) {
        if (n & 1) res = op(res, a);
        if (n >>= 1) a = op(a, a);
    }
    return res;
}

template <unsigned Mod> struct Modular {
    using M = Modular;
    unsigned v;
    Modular(long long a = 0) : v((a %= Mod) < 0 ? a + Mod : a) {}
    inline M operator-() const { return M() -= *this; }
    inline M& operator+=(M r) { if ((v += r.v) >= Mod) v -= Mod; return *this; }
    inline M& operator-=(M r) { if ((v += Mod - r.v) >= Mod) v -= Mod; return *this; }
    inline M& operator*=(M r) { v = (uint64_t)v * r.v % Mod; return *this; }
    inline M& operator/=(M r) { return *this *= power(r, Mod - 2); }
    friend M operator+(M l, M r) { return l += r; }
    friend M operator-(M l, M r) { return l -= r; }
    friend M operator*(M l, M r) { return l *= r; }
    friend M operator/(M l, M r) { return l /= r; }
    friend bool operator==(M l, M r) { return l.v == r.v; }
};

using Mint = Modular<mod>;

vector<Mint> fact, inv_fact, minv;
void prepare(int n) {
    fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
    for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
    inv_fact[n] = 1 / fact[n];
    for (int i = n; i; --i) inv_fact[i - 1] = i * inv_fact[i];
    for (int i = 1; i <= n; ++i) minv[i] = inv_fact[i] * fact[i - 1];
}
Mint binom(int n, int k) {
    if (k < 0 or k > n) return 0;
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template<> Mint& Mint::operator/=(Mint r) {
    return *this *= r.v < minv.size() ? minv[r.v] : power(r, mod - 2);
}
/***********************************************************************/
const int MAXN = 100009;
int p[MAXN][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i][0] >> p[i][1];
    // 도형의 연속적인 절반의 contour가 나머지 절반과 정확히 180도 돌렸을 때 같아야 
    // 원점을 기준으로 평행이동 시켰을 때 similar할 수 있다.
    
    if (n & 1) { //그러므로 점이 홀수개 일 땐 무조건 불가능하다.
        cout << "NO\n";
        return 0;
    }
    
    p[n][0] = p[0][0];
    p[n][1] = p[0][1];
    for (int i = 0; i < n / 2; ++i)
        //뺄셈 방향이 서로 반대라는 점에 주의하자.
        if (p[i + n / 2][0] - p[i + n / 2 + 1][0] != p[i + 1][0] - p[i][0] || 
            p[i + n / 2][1] - p[i + n / 2 + 1][1] != p[i + 1][1] - p[i][1])  
        {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n";
    return 0;
}
