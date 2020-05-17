/* #lev2 #Math */

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
#include <numeric>
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
typedef unsigned int			uint;
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/
/* if x < a, x < b
 * no answer
 * 
 * Period = (a,b)'s LCM
 * if a % b or b%a is 0, no answer.
 * 
 * else if (a, b) or (b, a) are no answer
 */
 
 uint gcd(uint a, uint b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

uint lcm(uint a, uint b){
    return a * b / gcd(a,b);
}
 
unsigned int a, b, q;
void sol(){
	cin >> a >> b >> q;
	if(a > b) swap(a, b);
	
	uint period = lcm(a, b);
	vector<int> mark(period);
	
	uint cnt(0);
	
	for(unsigned int i=0; i<period;i++){
		if(i<b) mark[i] = cnt;
		else mark[i]=(++cnt);
	}
	
	for(unsigned int i=0; i<q;i++){
		ll l, r;
		cin >> l >> r; l--;
		ll rn = (r/period)*cnt + mark[r%period];
		ll ln  = (l/period)*cnt + mark[l%period];
		cout << (rn - ln) << ' ';
	}
	cout << endl;
}



int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--)
		sol();
		
    return 0;
}
