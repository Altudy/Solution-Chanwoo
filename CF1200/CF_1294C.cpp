// [Tag]
// #lev2 #수학

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
using namespace std;

#define fi     	first    
#define se     	second  

/** Type Define **/
typedef long long int           ll;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<string>          vs;
typedef vector<bool>            vb;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;

constexpr int               inf =   	2123456789;
constexpr long long 		INF = 		9123456789123456789;
constexpr long long         MOD =       1000000007LL;



/*************************************************/

int T;
// 굳이 소인수분해를 전부 해주지 않아도 괜찮았다. 최대공약수나 최소공배수를 찾는 문제가 아니었기 때문에
// 2를 찾고 바로 break를 걸더라도 4를 다시 검사하므로 2가 몇개 들어가는지 세지 않아도된다.
void sol(int n) {
    vi facto; 
    vi ans;
    int ori = n;
    int ans_cnt(0);
    for (int i = 2; i*i <= n && ans_cnt < 2; i++) {
        while (n % i == 0) {
            facto.push_back(i);
            n /= i;
        }
    }
    if (n > 1) facto.push_back(n);

    /*for (auto x : facto)
        cout << x << " ";
    cout << endl;*/

    int f_size = facto.size();
    bool chk(false);
    int div(1);
    int a , b = 1, c;
    int other(1), same(1);
    for (int i = 0; i < f_size && !chk; i++) {
        ans.push_back(facto[i]);
        int x = 1;
        for (int j = i + 1; j < f_size && !chk; j++) {
            x *= facto[j];
            if (ans.back() != x) {
                ans.push_back(x);
                int rest = (ori / ans[0]) / ans[1];
                if (rest > 1 && ans[0] != rest && ans[1] != rest) {
                    cout << "YES\n" << ans[0] << " " << ans[1] << " " << rest << '\n';
                    chk = true;
                }
                ans.pop_back();
            }
                
        }
        ans.pop_back();
    }

    if (chk == false)
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    /*INPUT*/
    cin >> T;
    /*Get_Answer*/
    while (T--) {
        int n;
        cin >> n;
        sol(n);
    }
    return 0;
}
