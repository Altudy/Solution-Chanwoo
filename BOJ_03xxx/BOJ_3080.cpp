// [Tag]
// #Trie #문자열처리 #lev4

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <deque>
#include <map>
#pragma warning(disable:4996)

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
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;

constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;


typedef struct _str
{
    char str[3001];
}STR;

bool cmp(const STR& a, const STR& b)
{
    return strcmp(a.str, b.str) > 0;
}

ll factorial[3003]{1LL, };
//char a[3001][3001];
STR a[3000];

ll result(int low, int high, int idx)
{
    if (high - low <= 1)
        return 1;
    ll ret = 1;
    int novi_low = low;
    int cnt = 1;

    for (int i = low + 1; i < high; ++i)
        if (a[novi_low].str[idx] != a[i].str[idx]) {
            ret = ret * result(novi_low, i, idx + 1) % MOD;
            novi_low = i;
            ++cnt;
        }

    ret = ret * result(novi_low, high, idx + 1) % MOD;
    return ret * factorial[cnt] % MOD;
}

int main() {

    char input[1 << 20];
    setvbuf(stdin, input, _IOFBF, sizeof(input));

    int n;
    scanf("%d", &n);
    for (ll i = 0; i < n; ++i) {
        scanf("%s", a[i].str);
        factorial[i + 1] = factorial[i] * (i + 1) % MOD;
    }
    sort(a, a + n, cmp);
    printf("%lld\n", result(0, n, 0));

    return 0;
}
