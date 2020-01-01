// 구슬 탈출2
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
typedef pair<pii, pii> pp;
int M, N;
char Map[10][10];

pp lean(const pp& pos, int dir) {
    
}

//BFS로 풀면 좀 더 낫지 않을까?
void sol(int idx) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << Map[i][j];
        cout << endl;
    }
        
}

void input() {
    cin >> N >> M;          // 3 < N, M <= 10
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Map[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    input();
    sol(0);

    return 0;
}
