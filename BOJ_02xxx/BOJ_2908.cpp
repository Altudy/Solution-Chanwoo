// #문자열처리 : 상수

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
    
    string A, B;

    cin >> A >> B;

    char larger;
    if (A[2] > B[2])
        larger = 'A';
    else if (A[2] < B[2])
        larger = 'B';
    else {
        if (A[1] > B[1])
            larger = 'A';
        else if (A[1] < B[1])
            larger = 'B';
        else {
            if (A[0] > B[0])
                larger = 'A';
            else
                larger = 'B';
        }
    }
    if (larger == 'A')
        cout << A[2] << A[1] << A[0];
    else
        cout << B[2] << B[1] << B[0];

    return 0;
}
