
#include <iostream>
using namespace std;

typedef long long int ll;

ll T, n, s;
int cite[100001];

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> s;
        ll sum(0), max_cite;
        int idx(0), max_idx(0);

        for (int i = 0; i < n; i++) {
            cin >> cite[i];
            sum += cite[i];
        }

        if (sum <= s) {
            cout << "0\n";
            continue;
        }
        else sum = 0;


        max_cite = cite[idx];
        while (sum  + cite[idx] - max_cite <= s && idx < n - 1) {
            if (max_cite < cite[idx]) {
                max_cite = cite[idx];
                max_idx = idx;
            }
            sum += cite[idx++];
        }
        if (sum <= s)
            cout << idx + 1 << "\n";
        else
            cout << max_idx + 1 << "\n";
    }

    return 0;
}
