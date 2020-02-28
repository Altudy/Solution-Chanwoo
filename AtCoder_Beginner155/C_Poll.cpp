/* #lev1 #문자열처리
  하지만 만약 입력이 매우 커진다면, 정렬에, 모든 문자열을 비교까지 해야하므로 
  복잡도가 너무 크다
  */
 
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
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/
void MX(int& a, int b) {
    if (a < b) a = b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vs v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    v.push_back("zzzzzzzzzzz");
 
    int votes(0);
    int mx(-1);
    vector<pair<int, string>>  p;
    for (int i = 0; i < n; i++) {
        votes++;
        if (v[i] != v[i + 1]) {
            p.push_back({ votes, v[i]});
            MX(mx, votes);
            votes = 0;
        }
    }
 
    for (int i = 0; i < p.size(); i++) {
        if (p[i].first == mx)
            cout << p[i].second << '\n';
    }
 
    return 0;
}
