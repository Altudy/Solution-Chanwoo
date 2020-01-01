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
int M, N;
string ans;
string str;
int ssize;

void sol(const string& str) {
    for (int i = 0; i < ssize; i++) {
        if (ans[i] != str[i])
            ans[i] = '?';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    cin >> N;
    cin >> ans;
    ssize = ans.size();
    for (int i = 1; i < N; i++) {
        cin >> str;
        sol(str);
    }

    cout << ans;
    return 0;
}
