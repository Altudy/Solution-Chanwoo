// #lev3
// 쿠키구입 ver3

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int sum[2001];

int solution(vector<int> cookie) {
    int answer = 0;
    int cookie_size = cookie.size();

    for (int i = 0; i < cookie_size; ++i)
        sum[i + 1] = sum[i] + cookie[i];

    // 1. Front(앞쪽 집합) 과 Back(뒤쪽 집합)을 비교한다.
    // 2. Front를 줄여서 Back과 동일하게 만들수 있는지 check.
    // # 중간에 나온 answer보다 Back이 작으면 Out(최대의 답을 찾아야하므로)
    // # Front를 줄여나가는 방식이므로 Back이 Front보다 크면 동일하게 맞출수 없다.-> Break.
    for (int m = 1; m < cookie_size; ++m) {
        int Front = sum[m];
        for (int r = m + 1; r <= cookie_size; ++r) {
            int Back = sum[r] - Front;
            
            if (answer >= Back) continue;   
            if (Back > Front) break;

            for (int l = 0; l < m; ++l)
                if (Back == Front - sum[l]) {
                    answer = max(answer, Back);
                    break;
                }
        }
    }
    return answer;
}

// 쿠키구입 ver1

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector< int > vi;
typedef vector< vector<int> > vvi;

int solution(vector<int> cookie) {
    int N = cookie.size();
    vvi Sum(N, vi(N, 0));
    vi ans;

    for (int i = 0; i < N - 1; i++) {
        Sum[i][i] = cookie[i];
        for (int j = i + 1; j < N; j++) {
            Sum[i][j] = Sum[i][j - 1] + cookie[j];
            if (Sum[i][j] % 2 == 1) continue;
            else {
                for (int jj = i + 1; jj <= j; jj++)
                    if (2 * Sum[i][jj] == Sum[i][j]) {
                        ans.push_back(Sum[i][jj]);
                        break;
                    }
                    else if (2 * Sum[i][jj] > Sum[i][j]) break;
            }
        }
            
    }
    if (ans.size() == 0)
        return 0;
    else {
        sort(ans.begin(), ans.end());
        return ans.back();
    }
}

// 쿠키구입 ver2

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef vector< int > vi;
typedef vector< vector<int> > vvi;

int solution(vector<int> cookie) {
    int N = cookie.size();
    vi Sum(N);
    int ans = -1;
    map<int, int> search;

    for (int i = 0; i < N - 1; i++) {
        search.clear();
        int sum = cookie[i];
        search[sum] = 1;
        for (int j = i + 1; j < N; j++) {
            sum += cookie[j]; search[sum] = 1;
            if (sum % 2 == 1 || sum <= ans/2) continue;
            else {
                if (search[sum / 2] == 1)
                    if (sum / 2 > ans)
                        ans = sum / 2;
            }
        }
    }

    if (ans == -1)
        return 0;
    else
        return ans;
}
