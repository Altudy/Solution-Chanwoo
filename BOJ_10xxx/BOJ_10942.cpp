// [Tag]
// #다이나믹 #lev2 #팰린드롬
#include <cstdio>
#include <cstring> //memset
#include <iostream>
#include <algorithm>    
using namespace std;

/** Type Define **/
typedef long long int           ll;
typedef pair<ll, ll>            p_ll;
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;

/*************************************************/
int N, M;
int X[2001];
int isPalin[2001][2001];

int main() {
    /*INPUT*/
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X[i];

    isPalin[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        isPalin[i][i] = 1;
        if (X[i - 1] == X[i])
            isPalin[i - 1][i] = 1;
    }
    
    for (int dist = 2; dist <= N - 1; dist++) {
        for (int i = 1; i <= N - dist; i++) {
            int j = i + dist;
            if (X[i] == X[j] && isPalin[i + 1][j - 1]) 
                isPalin[i][j] = 1;
        }
    }

    /*Get_Answer*/
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << isPalin[a][b] << '\n';
    }

    return 0;
}
