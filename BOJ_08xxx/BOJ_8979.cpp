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
int K, N;
int M[1001][3];
int up_K(0);

void comp(int C, int K) { 
/*2개의 국가를 대표하는 숫자를 받아서 두 국가를 비교
  C국가가 더 등수가 높으면 up_K를 1증가 시킨다.*/
    if (M[C][0] < M[K][0]) return;
    else if (M[C][0] > M[K][0]) up_K++;
    else {
        if (M[C][1] < M[K][1]) return;
        else if (M[C][1] > M[K][1]) up_K++;
        else {
            if (M[C][2] < M[K][2]) return;
            else if (M[C][2] > M[K][2]) up_K++;
            else return;
        }
    }
}

void input() {
    cin >> N >> K;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        cin >> M[num][0] >> M[num][1] >> M[num][2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    input();
    for (int i = 1; i <= N; i++) {
        if (i == K)  continue;
        else comp(i, K);
    }
    cout << up_K + 1 << endl;

    return 0;
}
