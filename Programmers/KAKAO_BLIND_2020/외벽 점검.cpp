// #lev4 #순열 #Bitmask #브루트포스

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
//#pragma warning(disable:4996)

using namespace std;


/** Type Define **/
typedef long long int           ll;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<string>          vs;
typedef vector<bool>            vb;
typedef vector<int>             vi;
typedef vector<long long>       vl;
typedef vector<vi>              vvi;
typedef vector<vl>              vvl;
typedef vector<char>            vch;

constexpr int               inf = 0x3f3f3f3f;
constexpr long long         INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/
typedef unsigned char uch;
int w_size, d_size;

// return the number of 1 bit in binary x.
int bitCount(int x) {
    if (x == 0) return 0;
    return x % 2 + bitCount(x / 2);
}

bool check(vi& w, int w_i, vi& d, int bit) {
    vi nd;
    int lo(w_i), hi(w_i + w_size - 1);
    //bit를 이용해 부분집합 생성.
    for (int i = 0; i < d_size; i++)
        if (bit & (1 << i)) nd.push_back(d[i]);
    

    //순열 돌면서 가능한지 체크.
    do {
        int idx(lo);
        for (int i = 0; i < nd.size(); i++) {
            // from w[idx]
            int to = w[idx] + nd[i];
            while (w[idx] <= to) {
                idx++;
                if (idx > hi) return true;
            }
        }
    } while (next_permutation(nd.begin(), nd.end()));
    
    //루프를 빠져나왔다는 것은 모든 외벽을 점검할 수 없었다는 것.
    return false;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    w_size = weak.size();
    d_size = dist.size();
    if (w_size == 1) return 1;
    
    // 외벽을 회전 시켜보면서 (길이가 n인)직선을 검사하기 위해 미리 뒷부분을 만들어둔다.
    for (int i = 0; i < w_size - 1; i++)
        weak.push_back(weak[i] + n);  
    
    
    // bit : d_size개의 bit를 이용해서 dist의 원소 중 어느 것을 사용할지 고른 다음,
    // check()내에서는 고른 원소들로 순열을 만들어 각각 검사한다. 
    // 그리고 하나라도 가능한 순열이 존재하면 최소의 선택인지 비교한다.
    int ans(inf);
    for (int i = 0; i < w_size; i++)
        for (int bit = 0; bit <= ((1 << d_size) - 1); bit++) 
            if (check(weak, i, dist, bit)) ans = min(ans, bitCount(bit));
        
    
    //답이 나오지 못했으면 불가능-> -1출력.
    if (ans == inf) return -1;
    else            return ans;
}
