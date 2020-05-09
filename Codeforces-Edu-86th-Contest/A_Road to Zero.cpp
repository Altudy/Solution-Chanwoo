/* #lev1 #greedy */

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
typedef unsigned int			uint;
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/
ll x, y, a, b;
void sol(){
	cin >> x >> y >> a >> b;
	//make x and y equal to zero;
	
	ll pay(0);
	
	if(x > 0 && y > 0) {
		ll both;
		if (2*a <= b) 	both = 2 * a;
		else 			both = b;
		
		ll k = min(x, y);
		pay += k * both;
		x -= k; y -= k;
	}
	
	if(x > 0) pay += (x * a);
	else if(y > 0) pay += (y*a);
	
	cout << pay << '\n';
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
