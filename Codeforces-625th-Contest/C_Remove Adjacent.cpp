/* #lev3 #linked_list #문자열처리 #아이디어      */

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
string s;
int l[105], r[105];
bool chk[105];
int main()
{
	int n, ans = 0;
	cin >> n;
	cin >> s;
	s = ' ' + s + ' ';

	for (int i = 1; i <= n; i++) {
		l[i] = i - 1;
		r[i] = i + 1;
		chk[i] = 1;
	}

	for (int i = 25; i >= 1; i--) // Z to A.
		for (int j = 1; j <= n; j++)// 이중 포문은 lr갱신으로 인한 정보를 놓치지 않기 위해서. k-loop를 n번 돌림.
			for (int k = 1; k <= n; k++) {
				if (!chk[k])continue;			//already removed place.
				if (s[k] != 'a' + i)continue;	//not i-th target.

				if (s[l[k]] == 'a' + i - 1 || s[r[k]] == 'a' + i - 1) {
					ans++; // remove one ++.

					//linked list- like array.
					l[r[k]] = l[k]; 
					r[l[k]] = r[k];
					chk[k] = 0;
				}
			}
		
	

	cout << ans << '\n';
	return 0;
}
