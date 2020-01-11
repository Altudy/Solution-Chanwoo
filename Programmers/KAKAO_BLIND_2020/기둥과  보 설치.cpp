//Tag : #lev2 #구현
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
void input() {

}

int P[105][105] = {};
int T[105][105] = {};


void setPost(int x, int y) {
    if (y == 0);
    else if (y > 0 && x > 0)
        if (P[x][y - 1] || T[x][y] || T[x - 1][y]);
        else return;
    else if (y > 0 && x == 0)
        if (P[x][y - 1] || T[x][y]);
        else return;
    else return;

    P[x][y] = 1;
}

void delPost(int x, int y) {
    if (P[x][y + 1])
        if (T[x][y + 1] || T[x - 1][y + 1]);
        else return;
    
    if (x >= 1 && T[x - 1][y + 1])
        if ((x >= 1 && P[x - 1][y]) || (x >= 2 && T[x - 2][y + 1] && T[x][y + 1]));
        else return;
    
    if (T[x][y + 1])
        if (P[x + 1][y] || (x >= 1 && T[x - 1][y + 1] && T[x + 1][y + 1]));
        else return;

    P[x][y] = 0;
    return;
}

void setTable(int x, int y) {
    if (y == 0) return;
    if (P[x][y - 1] || P[x + 1][y - 1])         T[x][y] = 1;
    if (x >= 1 && T[x - 1][y] && T[x + 1][y])   T[x][y] = 1;
}

void delTable(int x, int y) { //y > 0
    if (y == 0) return;
    if (P[x][y])
        if (P[x][y - 1] || (x > 0 && T[x - 1][y]));
        else return;
    
    if (P[x + 1][y])
        if (P[x + 1][y - 1] || (T[x + 1][y]));
        else return;
    
    if (x > 0 && T[x - 1][y])
        if (P[x - 1][y - 1] || P[x][y - 1]);
        else return;
    
    if (T[x + 1][y])
        if (P[x + 1][y - 1] || P[x + 2][y - 1]);
        else return;

    T[x][y] = 0;
    return;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int b_size = build_frame.size();
    for (int work = 0; work < b_size; work++) {
        int x = build_frame[work][0];
        int y = build_frame[work][1];
        if (x > n || y > n) continue;
        if (build_frame[work][2] == 0) {
            if (build_frame[work][3] == 1 && y < n)  setPost(x, y);
            else                            delPost(x, y);
        }
        else if (build_frame[work][2] == 1) {
            if (build_frame[work][3] == 1 && x < n)  setTable(x, y);
            else                            delTable(x, y);
        }
            
    }

    for(int x = 0; x <= n; x++)
        for (int y = 0; y <= n; y++) {
            if (P[x][y]) answer.push_back(vector<int>{x, y, 0});
            if (T[x][y]) answer.push_back(vector<int>{x, y, 1});
        }


    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int n = 5;
    vvi build_frame = { {0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1} };
    solution(n, build_frame);
    return 0;
}
