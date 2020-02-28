/* #                          */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <deque>x
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
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/

void normalize(vi& num) {
    //Overflow 방지.
    num.push_back(0);

    //자릿수 올림.
    for (int i = 0; i + 1 < num.size(); i++) {
        if (num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }

    //overflow방지용 자리가 쓰이지 않았을 경우 다시 처리.
    while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vi multiply(const vi& a, const vi& b) {
    vi c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j)
            c[i + j] += a[i] * b[j];
    }
    normalize(c);
    return c;
}

void addTo(vi& a, const vi& b, int k) {
    int an(a.size()), bn(b.size());
    if (an < bn + k) a.resize(bn + k);
    for (int i = 0; i < bn ; i++) {
        a[k + i] += b[i];
    }
    normalize(a);
}
void subFrom(vi& a, const vi& b) {
    int an(a.size()), bn(b.size());
    if (an < bn) a.resize(bn);
    for (int i = 0; i < bn; i++) {
        a[i] -= b[i];
    }
    normalize(a);
}

vi karatsuba(const vi& a, const vi& b) {
    int an = a.size(), bn = b.size();

    if (an < bn) return karatsuba(b, a);

    if (an == 0 || bn == 0) return vi();

    //1번 if에 의해 무조건 an은 사이즈가 큰쪽
    if (an <= 10) return multiply(a, b);
    int half = an / 2;

    vi a0(a.begin(), a.begin() + half);
    vi a1(a.begin() + half, a.end());

    int b_half = min<int>(b.size(), half);
    vi b0(b.begin(), b.begin() + b_half);
    vi b1(b.begin() + b_half, b.end());

    vi z2 = karatsuba(a1, b1);
    vi z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0); addTo(b0, b1, 0);

    vi z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vi ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    vi a({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3});
    vi b({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3});
    vi c = karatsuba(a, b);
    for (auto& x : c) cout << x << ' ';
    cout << endl;
    // output : 1 4 0 1 7 9 9 8 7 9 3 1 5 3 5 9 4 0 6 7 6 3 0 1
    // Google : 1.0367605e+23


    return 0;
}
