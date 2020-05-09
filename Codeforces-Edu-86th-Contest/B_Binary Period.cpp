/* #lev1 #구현 */

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
string t;

void sol(){
	cin >> t;
	int len = t.size();
	int ones(0), zeros(0);
	for(int i=0; i<len ;i++)
		if(t[i] == '1') ones++;
		else 			zeros++;
	
	if(zeros == 0 || ones == 0) {
		cout << t << '\n'; return;
	}
	
	string pat; //pattern
	if(t[0] == '0') pat = "01";
	else pat = "10";
	
	t += '2';
	
	string s;
	for(int i=0; i<len; ){
		string tmp = string() + t[i] +t[i+1];
		if (tmp == pat) {
			s += pat;
			i += 2;
		}
		else{
			s += pat;
			i += 1;
		}
	}
	
	cout << s << '\n';
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
