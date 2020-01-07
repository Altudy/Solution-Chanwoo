// #lev1 #문자열처리 #패턴

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sub(const string& s, int block) {
    int ans(0);
    int cnt(0);
    string B;
    auto it = s.begin();
    for (int i = 0; i < block; i++, ++it) B += *it;

    while (it != s.end()) {
        string BB;
        for (int i = 0; i < block && it != s.end(); ++i, ++it) BB += *it;
        if (BB == B) cnt++;
        else {
            if (cnt) {
                cnt++;
                int cnt_size(0);
                while (cnt > 0) cnt_size++, cnt /= 10;
                ans += (cnt_size + block);
            }
            else ans += block;
            cnt = 0;
            B = BB;
        }
    }
    if (cnt) {
        int cnt_size(0);
        cnt++;
        while (cnt > 0) cnt_size++, cnt /= 10;
        ans += (cnt_size + block);
    }
    else ans += B.size();

    return ans;
}

int solution(string s) {
    int s_size = s.size();
    int mn(987654321);

    if (s_size == 1) return 1;
    for (int i = 1; i <= s_size / 2; i++)
        mn = min(mn, sub(s, i));

    return mn;
}
