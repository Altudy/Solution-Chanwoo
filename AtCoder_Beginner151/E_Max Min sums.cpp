/* #lev3 #Math                          */

#include <iostream>
#include <iomanip>
#include <cassert>
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

///
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
    M operator-() const { return M() -= *this; }
    M& operator+=(M r) { if ((v += r.v) >= Mod) v -= Mod; return *this; }
    M& operator-=(M r) { if ((v += Mod - r.v) >= Mod) v -= Mod; return *this; }
    M& operator*=(M r) { v = (uint64_t)v * r.v % Mod; return *this; }
    M& operator/=(M r) { return *this *= power(r, Mod - 2); }
    friend M operator+(M l, M r) { return l += r; }
    friend M operator-(M l, M r) { return l -= r; }
    friend M operator*(M l, M r) { return l *= r; }
    friend M operator/(M l, M r) { return l /= r; }
    friend bool operator==(M l, M r) { return l.v == r.v; }
};

constexpr long long mod = 1e9 + 7;
using Mint = Modular<mod>;

vector<Mint> fact, inv_fact, minv;
void prepare(int n) {
    fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
    fact[0] = Mint(1);
    for (int i = 1; i <= n; ++i) fact[i] = i * fact[i - 1];
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


#define   all(x) 			x.begin(), x.end()
constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/
ll N, K;
vl a;
// COmbination을 구현할때, factorial과 inv_factorial를 가지고 연산하자.


int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
    cin >> N >> K;
    prepare(N);
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(all(a), greater<ll>());

    ll mx_sum(0);
    ll mn_sum(0);
    for (int i = 0; i < N - K + 1; i++) {
        ll nCr = (ll)binom(N - i - 1, K - 1).v;
        //cout << "nCr : " << nCr << endl;
        mx_sum = (mx_sum + (ll(a[i]) * nCr) % mod) % mod;
        mn_sum = (mn_sum + (ll(a[N - 1 - i]) * nCr) % mod) % mod; //곳곳의 -, + 연산에 mod를 넘어갈수 있으므로 항상 체크.
    }
    // 답이 MOD연산을 강제 하고 있기 때문에 -값들을 mod연산시켜 돌려주어야 하는듯.
    ll ans = (mx_sum - mn_sum) % mod;
    cout << (ans + mod) % mod << endl;

    return 0;
}
