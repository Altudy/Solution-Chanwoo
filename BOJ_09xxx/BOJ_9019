//Tag : #문자열처리 #중복처리
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

string str;
int X;          //문자열이 바뀌는 횟수.
int str_size;

void input() {
    cin >> X >> str;
    str_size = str.length();
}

int find_loop() {   
    //X의 상한이 너무 크므로 분명 문자열이 다시 처음으로 돌아오는 지점이 있을 것이라고 판단.
    int cnt(0);
    string c_str, ori_str = str;
    c_str.resize(str_size);
    int mid_i = (str_size - 1) / 2;
    
    while (1) { 
        //문제에서 정의한 1번 깜박일때 문자열 변형.
        for (int i = 0; i < str_size; i++) {
            if (i <= mid_i)
                c_str[2 * i] = str[i];
            else {
                int n_i = 2 * (str_size - i) - 1;
                c_str[n_i] = str[i];
            }
        }
        str = c_str;
        cnt++;
        if (c_str == ori_str) break; //같아질 때 break;
    }
    str = ori_str;
    return cnt; // cnt 번 깜박이면 문자열은 그대로.
}

void sol() {
    //전역 변수인 str을 1번 깜박이기 전의 상태로 되돌림.
    string n_str;
    n_str.resize(str_size);

    for (int i = 0; i < str_size; i++) {
        if (i % 2 == 0)
            n_str[i / 2] = str[i];
        else if (i % 2 == 1) {
            int n_i = str_size - (i + 1) / 2;
            n_str[n_i] = str[i];
        }
    }
    str = n_str;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    input();
    X %= find_loop(); //문자열이 중복되지 않는 만큼만 연산.

    while (X--) sol();//str이 최종 문자열이므로 1번씩 상태를 되돌린다.
 
    cout << str << endl;
    return 0;
}
