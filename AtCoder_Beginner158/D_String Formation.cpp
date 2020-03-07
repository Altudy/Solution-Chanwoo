/* #lev2 #문자열처리                          */

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
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/
int rvs(0); //reverse check;
string s;
string back, front;
int Q;

/* 어차피 앞뒤에 붙어가는 문자열은 순서가 일정하므로 back과 front를 관리한 뒤 마지막에 합쳐준다.
*/
void add(int& op2, char& e) {
    if (rvs) {
        if (op2 == 1) back.push_back(e);
        else front.push_back(e);
    }
    else {
        if (op2 == 1) front.push_back(e);
        else back.push_back(e);
    }
}
void sol() {
    int op; cin >> op;
    if (op == 1) {
        rvs ^= 1;
    }
    else {
        int op2;    cin >> op2;
        char e;     cin >> e;
        add(op2, e);
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

    cin >> s;
    cin >> Q;
    while (Q--)
        sol();

    if (rvs) {
        reverse(all(back));
        reverse(all(s));
        cout << back << s << front << endl;
    }
    else {
        reverse(all(front));
        cout << front << s << back << endl;
    }

    return 0;
}
