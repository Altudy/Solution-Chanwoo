//#lev1 #문자열처리
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

#define Inf             987654321
using namespace std;

typedef long long int   ll;
typedef pair<ll, ll>    pii;
typedef vector<ll>      vi;
typedef vector<vi>      vii;
/*************************************************/
int N;

void sol(int n) {
    string s = to_string(n);
    int cnt(0);
    for (auto ch : s)
        if (ch == '3' || ch == '6' || ch == '9')
            cnt++;
    if (!cnt)
        cout << s;
    else
        while (cnt--) cout << '-';
    cout << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> N;
    for (int i = 1; i <= N; i++)
        sol(i);

    return 0;
}
