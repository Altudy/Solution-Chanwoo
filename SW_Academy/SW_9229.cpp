//Tag : #lev1 #브루트포스
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

int T, N, M;
vector <int> a;

void input() {
    cin >> T;
}

//그리디로 구하게 되면 가장 큰 원소와 맞는 조합을 찾느라 2, 3번째로 조합되는 최적값을 찾지 못할수 있다.
//-> 2<=N<=1000 이므로 모든 경우를 비교해도 최대 500000만에 찾을수는 있음.
int sol() {
    cin >> N >> M;
    a.assign(N, 0);
    int mx(-1);

    cin >> a[0];
    for (int i = 1; i < N; i++) { //새로운 값을 받을 때마다 전에 원소들과 더해보며 max값과 비교해본다.
        cin >> a[i];              // 1 + 2 + 3 + 4 + ... + N-1 = N(N-1)/2
        if (a[i] > M) continue;
        for (int pre = 0; pre < i; pre++)
            if (a[pre] + a[i] > mx && a[pre] + a[i] <= M)
                mx = a[pre] + a[i];
    }
    a.clear();
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    input();
    for (int t = 1; t <= T; t++)
        cout << "#" << t << " " << sol() << endl;;
    return 0;
}
