//#문자열처리: 그룹 단어 체커
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
int N, ans(0);
string s;

void sol(const string& str) {
    bool check[26] = {};
    int size = str.size();
    for (int i = 0; i < size; i++) {
        int idx = int(str[i] - 'a');
        if (check[idx])
            return;
        else {
            check[idx] = true;
            while (i < size && str[i] == str[i + 1])
                i++;
        }
    }
    ans++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        sol(s);
    }


    cout << ans;
    return 0;
}
