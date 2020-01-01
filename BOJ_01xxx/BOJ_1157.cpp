// #문자열처리 : 단어 공부

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

int A[26] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    string str;
    cin >> str;
    int size = str.size();

    for (int i = 0; i < size; i++) {
        if (islower(str[i]))
            str[i] = toupper(str[i]);

        int s = int(str[i] - 'A');
        A[s]++;
    }

    int mx(0);
    char mxi('?');
    for (int i = 0; i < 26; i++) {
        if (mx < A[i]) {
            mx = A[i];
            mxi = char('A' + i);
        }
        else if (mx == A[i])
            mxi = '?';
        else;
    }
        cout << mxi;
    
    return 0;
}
