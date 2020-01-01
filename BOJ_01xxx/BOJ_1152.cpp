// #문자열처리 : 단어의개수

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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    string s; int cnt(0);
    getline(cin, s);
    
    int size = s.length();
    for (int i = 0; i < size; i++)
        if (s[i] == ' ')
            cnt++;

    cnt = cnt - (s[0] == ' ') - (s[size - 1] == ' ') + 1;

    cout << cnt;
    

    return 0;
}
