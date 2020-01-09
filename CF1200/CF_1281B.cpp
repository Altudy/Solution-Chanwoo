//Tag : #lev1 #문자열처리 #아이디어
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
// A string으로 만들수 있는 가장 작은 문자열을 만든 뒤 B string과 비교.

int T;
string A, B;

void input() {
    cin >> T;
}

string sol() {
    cin >> A >> B;
    if (A < B) return A;

    int A_size = A.size();
    for (int idx = 0; idx < A_size; idx++) {
        int mn_i(idx);
        for (int i = idx + 1; i < A_size; i++)
            if (A[i] <= A[mn_i]) mn_i = i;
        if (A[mn_i] < A[idx]) {
            swap(A[mn_i], A[idx]);
            break;
        }
    }

    if (A < B) return A;
    else return "---";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    input();
    while (T--)
        cout << sol() << '\n';
    return 0;
}
