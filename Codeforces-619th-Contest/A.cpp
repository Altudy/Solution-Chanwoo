/* #                          */

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
int T;

void sol() {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == c[i] || b[i] == c[i]) continue;
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        sol();
    }


    return 0;
}
