//Tag : #브루트
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

#define Inf                     987654321
using namespace std;

typedef long long int           ll;
typedef pair<ll, ll>            pii;
typedef vector<ll>              vi;
typedef vector<vi>              vii;
typedef vector<char>            vch;
typedef vector<bool>            vb;
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;
/*************************************************/

char button[10][17] = {
    "1110000000000000",
    "0001000101010000",
    "0000100000100011",
    "1000111100000000",
    "0000001110101000",
    "1010000000000011",
    "0001000000000011",
    "0000110100000011",
    "0111110000000000",
    "0001110001000100"
};

int cnt(0);
int ans(Inf);
int what_but(0);

void push_button(int *clock, int type, int n) {
    for (int i = 0; i < 16; i++) {
        if (button[type][i] - '0') {
            clock[i] += abs(n) * 3;
            if (clock[i] > 12) 
                clock[i] -= 12;
        }
    }
    if (n >= 0) cnt += n;
    else cnt -= (4 + n);
}

void sol(int *clock) {
    bool e(true);
    for (int i = 0; i < 16; i++)
        if (clock[i] != 12) e = false;

    if (e) {
        if (cnt < ans) ans = cnt;
        return;
    }

    if (what_but == 10)
        return;

    
    
    for (int i = 0; i < 4; i++) {
        push_button(clock, what_but, i);
        what_but++;
        sol(clock);
        push_button(clock, what_but - 1, i - 4);
        what_but--;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int C;
    cin >> C;
    for (int i = 0; i < C; i++) {
        int clock[16]; cnt = 0; 
        ans = Inf; what_but = 0;
        for (int i = 0; i < 16; i++)
            cin >> clock[i];
        sol(clock);
        if (ans == Inf) cout << -1 << endl;
        else cout << ans << endl;

    }
    


    return 0;
}

/*************************교재풀이***********************/

const int Inf = 9999, SWITCH = 10, CLOCK= 16;

const char linked[SWITCH][CLOCK] = {
    "xxx.......",
    ........//연결 정보 채움
}

bool areAligned(const vector<int>& clocks){
    //모든 시계가 12시를 가르키는지 확인
}

void push(vector<int>& clocks, int swtch){
    for(int clock=0; clock <CLOCK; clock)
        if(linked[swtch][clock] == 'x'){
            clock[clock] += 3;
            if(clocks[clock] == 15) clocks[clock] = 3;
        }
}

int solve(vector<int>& clocks, int swtch){
    if(swtch == SWITCH) return areAligned(clocks) ? 0 : Inf;
    int ret = Inf;
    for(int cnt = 0; cnt <4; ++cnt){
        ret = min(ret, cnt + solve(clocks, swwthc + 1)); // cnt : 이 단계에서만 누른 버튼
        push(clocks, swtch);
    }
    //push를 4번 호출 하면 다시 원래 자리로 돌아온다. - SIMPLE!
    return ret;
}
