// #lev3

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
