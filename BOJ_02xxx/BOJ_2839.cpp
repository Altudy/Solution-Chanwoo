#include <iostream>
#include <string>
#include <limits.h>
#include <vector>
#include <algorithm>
#define x first
#define y second

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<bool> vb;
typedef vector<char> vch;
typedef pair<ll, ll> pii;

/**********Actual Code***********/
//GLOB
int N;

//FUNC
void input() {
    cin >> N;
}

int sol() {
    if (N % 3 == 0) 
        return (N / 15) * 3 + (N % 15) / 3;
    else if (N % 3 == 1) {
        N -= 10;
        if (N >= 0)
            return (N / 15) * 3 + (N % 15) / 3 + 2;
        else
            return -1;
    }
    else {  // (N % 3 == 2)
        N -= 5;
        if (N >= 0)
            return (N / 15) * 3 + (N % 15) / 3 + 1;
        else
            return -1;
    }
}
//MAIN
int main() {
    ios::sync_with_stdio(false);
    input();
    cout << sol();
    return 0;
}
