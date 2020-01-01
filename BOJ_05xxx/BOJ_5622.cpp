//#문자열처리 : 
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
int Num[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    string str;
    cin >> str;


    int size = str.size();
    
    int ans(0);
    for (int i = 0; i < size; i++) {
        int idx = int(str[i] - 'A');
        ans += (Num[idx] + 1);
    }

    cout << ans;
    return 0;
}
