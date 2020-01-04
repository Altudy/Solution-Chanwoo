//Tag : #탐색 #브루트 #DFS
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
typedef vector<char>    vch;
typedef vector<bool>    vb;
/*************************************************/
int C, H, W, ans, w_block;
int block_type[4][3][2] = { // 왼위 기준4가지 블록 타입
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {-1, 1}, {0, 1}}
};

void input(vector<vch>& B) {
    cin >> H >> W;
    B.assign(H, vch(W, 0));
    char b;
    w_block = 0; ans = 0;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            cin >> b;
            if (b == '#') B[i][j] = 1; // 채운 칸을 true로 설정.
            else w_block++;
        }
    //cout << "w : " << w_block << endl;
}

bool setBlock(vector<vch>& B, int row, int col, int type, int set) {
    //set : 1 or -1
    bool ok(true);
    for (int i = 0; i < 3; i++) {
        int nr = row + block_type[type][i][1];
        int nc = col + block_type[type][i][0];
        if (nr < 0 || nr >= H || nc < 0 || nc >= W) ok = false;
        else if ((B[nr][nc] += (char)set) > 1) ok = false;
    }
    return ok;
}

void sol(vector<vch>& B) {
    int row(-1), col(-1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            if (B[i][j] == 0) {
                row = i, col = j;
                break;
            }
        if (row != -1) break;
    }

    if (row == -1 && col == -1) {// 블록을 전부 채운 케이스.
        ans++; return;
    }

    for (int i = 0; i < 4; i++) {
        if (setBlock(B, row, col, i, 1))
            sol(B);
        setBlock(B, row, col, i, -1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        vector<vch> B;
        input(B);
        if (w_block % 3 != 0) {
            cout << 0 << endl;
            continue;
        }
        sol(B);
        cout << ans << endl;
    }


    return 0;
}
