//#문자열처리 : 알파벳 찾기

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

int A[26]; // a~z를 0~25의 인덱스로 처리하여 처음 나타난 위치 저장.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    for (int i = 0; i < 26; i++)
        A[i] = -1;

    string str;
    cin >> str;

    int size = str.size();
    for (int i = 0; i < size; i++) {
        int s = int(str[i] - 'a');
        if (A[s] == -1)
            A[s] = i;
    }

    for (int i = 0; i < 26; i++)
        cout << A[i] << " ";
    
    

    return 0;
}
