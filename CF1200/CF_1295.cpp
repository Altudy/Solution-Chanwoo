// #lev2 #구현
#include <iostream>
#include <iomanip>
using namespace std;

#define OutWith(x) return void(cout << x << endl)

bool check(int bal, int x, int cycle) {
    int val = x - bal;
    if (val % cycle != 0) return false;
    int div = val / cycle;
    if (div < 0) return false;
    return true;
}

void sol() {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    int cycle = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') ++cycle;
        else --cycle;
    }

    // the case exists infinite cycle.
    if (cycle == 0) {
        int bal = 0;
        if (bal == x) OutWith(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') ++bal;
            else --bal;
            if (bal == x) OutWith(-1);
        }
        OutWith(0);
    }

    // s string's each element can be answer only once using (k*cycle ,for k >= 0).
    if (cycle != 0) {
        int bal = 0;
        int res = 0;
        res += check(bal, x, cycle);
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') ++bal;
            else --bal;
            res += check(bal, x, cycle);
        }
        OutWith(res);
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--)
        sol();

    return 0;
}
