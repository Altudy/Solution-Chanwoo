//Tag : #lev1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

#define Inf                     1001001001
using namespace std;

typedef long long int           ll;
typedef pair<ll, ll>            p_ll;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;
/*************************************************/

int T;

void input() {
    cin >> T;
}

void sol() {
    string str;
    int numer;
    int denom = 1;
    cin >> str;
    int idx = str.size() - 1;
    if (str.back() == 'h')
        numer = 0, idx -= 5;
    else if (str.back() == 't')
        numer = 90, idx -= 4;

    while (idx > 0) {
        denom *= 2;
        if (str[idx] == 't') {
            numer = 2 * numer + 90;
            idx -= 4;
        }
        else if (str[idx] == 'h') {
            numer = 2 * numer - 90;
            idx -= 5;
        }
        else continue;
    }

    while (numer % 2 == 0 && denom != 1) {
        numer /= 2;
        denom /= 2;
    }

    cout << numer;
    if (denom == 1);
    else cout << '/' << denom;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    input();
    for (int t = 1; t <= T; t++)
        cout << "#" << t << " ",  sol();
    return 0;
}
