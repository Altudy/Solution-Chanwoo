//#DFS #다이나믹 #재귀
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
int M, N;
int D[50][50] = {}; // 각 자리에서의 최대 움직임
char B[50][50];     //Board.
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int sol(int x, int y) {
    int temp, mx(0);         //candidate direction
    char *here = &B[y][x];      //현재 칸의 숫자 파악 + 여러번 접근하는 변수이므로
                                //포인터로 선언하여 처리속도 개선.
    int d = int(*here - '0');   //char->int변환,

    for (int i = 0; i < 4; i++) {
        int nx = x + d * dx[i];
        int ny = y + d * dy[i];

        //아래 3가지 예외에 걸릴시 각각 처리.
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) //벗어난 경우
            continue;
        if (B[ny][nx] == 'H')   //움직였을 때 구멍인 경우.
            continue;
        if (B[ny][nx] == 'X')   //움직였을 때 지나왔던 곳일 경우->무한루프생성.
            return -1;
        
        if (D[ny][nx] == 0) {
            char tempB = B[y][x];
            *here = 'X';    //지나간 곳 표시.
            temp = sol(nx, ny);
            *here = tempB;  //표시 풀기.
            if (temp == -1) //sol()에서 무한루프 발견한경우 처리.
                return -1;
        }
        else
            temp = D[ny][nx];
            
        if (mx < temp)
            mx = temp;
    }

    if (D[y][x] == 0)
        D[y][x] = 1 + mx;
    return 1 + mx;
}

void input() {
    cin >> N >> M;
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
            cin >> B[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    input();

    cout << sol(0, 0) << endl;

    return 0;
}
