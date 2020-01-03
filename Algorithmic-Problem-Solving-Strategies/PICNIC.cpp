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
int C, m, n;
bool chk_f[10][10]{};
bool chk[10];
int cnt(0), ans(0);


void input() {
    cin >> n >> m;
    cnt = n; ans = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            chk_f[i][j] = false;
    for (int j = 0; j < 10; j++)
        chk[j] = false;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        chk_f[a][b] = (chk_f[b][a] = true);
    }
}

void sol() {
    

    for (int f1 = 0; f1 < n; f1++) {
        if (!chk[f1]) {
            for (int f2 = f1 + 1; f2 < n; f2++) {
                if (chk[f2] || !chk_f[f1][f2]) continue;
                else {
                    chk[f1] = (chk[f2] = true);
                    sol();
                    chk[f1] = (chk[f2] = false);
                }
            }
            return;
        }
        else continue;
    }

    ans++; 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> C;
    for (int i = 1; i <= C; i++)
        input(), sol(), cout << ans << endl;
    
    return 0;
}
