
#include <iostream>
#include <string>
#include <map>
#include <limits.h>
#include <vector>
#include <algorithm>
#define x first
#define y second

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<bool> vb;
typedef vector<char> vch;
typedef pair<ll, ll> pii;
/**********Actual Code***********/
//GLOB
int N;
typedef pair<string, int> psi;
map<string, ll> mp;

void input() {
	cin >> N;
}

void sol() {
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (mp[str] == 0)
			cout << "OK\n";
		else cout << str << mp[str] << '\n';
		mp[str]++;
	}
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	sol();
	return 0;
}
# A map requires O(log(N)) time for inserts and finds operations, 
# as it's implemented as a Red-Black Tree data structure.
# An unordered_map requires an 'average' time of O(1) for inserts and finds, 
# but is allowed to have a worst - case time of O(N).This is because it's implemented using Hash Table data structure.
