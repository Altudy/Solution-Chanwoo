//#문자열처리 : 크로아티아 알파벳
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
string s;
int ans;

void sol() {
    int s_size = s.size();
    for (int i = 0; i < s_size-2; i++) {
        ans++;
        if (s[i] == 'c')
            if (s[i + 1] == '-' || s[i + 1] == '=')
                i++;
        if (s[i] == 'd')
            if (s[i + 1] == '-')
                i++;
            else if (s[i + 1] == 'z' && s[i + 2] == '=')
                i += 2;
        if (s[i] == 'l')
            if (s[i + 1] == 'j')
                i++;
        if (s[i] == 'n')
            if (s[i + 1] == 'j')
                i++;
        if (s[i] == 's')
            if (s[i + 1] == '=')
                i++;
        if (s[i] == 'z')
            if (s[i + 1] == '=')
                i++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> s;
    s += "00";
    sol();

    return 0;
}
