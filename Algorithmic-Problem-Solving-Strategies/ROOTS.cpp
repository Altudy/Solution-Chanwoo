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
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;


#define   all(x) 			x.begin(), x.end()
constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/
int T, n;
const double L = 25;

double evaluate(const vector<double>& poly, double x0) {
    double ret(poly.back());
    double co(x0);
    for (int i = poly.size() - 2; i >= 0; i--) {
        ret += poly[i] * co;
        co *= x0;
    }
    return ret;
}
vector<double> differentiate(const vector<double>& poly) {
    int sz = poly.size() - 1;
    vector<double> ret(sz);
    double co(1);
    for (int i = sz - 1; i >= 0; i--) {
        ret[i] = poly[i] * co; co++;
    }
    /*for (auto& x : ret) cout << x << " ";
    cout << endl;*/
 
    return ret;
}

vector<double> solveNaive(const vector<double>& poly) {
    vector<double> ret;
    int sz = poly.size() - 1;
    if (sz == 1) {
        ret.push_back(-poly[0] / poly[1]);
        return ret;
    }

    double a(poly[0]), b(poly[1]), c(poly[2]);
    double d = b * b - 4 * a * c;

    if (d > 0) {
        ret.push_back((-b - sqrt(d)) / 2 / a);
        ret.push_back((-b + sqrt(d)) / 2 / a);
    }
    else if (d == 0) {
        ret.push_back((-b / 2 / a));
    }
    else cout << "No solution\n";

    return ret;
}

vector<double> sol(const vector<double>& poly) {
    int sz = poly.size() - 1;
    if (sz <= 2) return solveNaive(poly);
    /*cout << "poly : ";
    for (auto& p : poly) cout << p << " ";
    cout << endl;*/
    vector<double> derivative = differentiate(poly);
    vector<double> sols = sol(derivative);
    
    sols.insert(sols.begin(), -L - 1);
    sols.insert(sols.end(), L + 1);
    /*cout << "sols : ";
    for (auto& s : sols) cout << s << " ";
    cout << endl;*/

    vector<double> ret;

    for (int i = 0; i + 1 < sols.size(); ++i) {
        double x1 = sols[i], x2 = sols[i + 1];
        double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
    
        if (y1 * y2 > 0) continue;

        if (y1 > y2) {
            swap(y1, y2); swap(x1, x2);
        }
        for (int iter = 0; iter < 100; iter++) {
            double mx = (x1 + x2) / 2, my = evaluate(poly, mx);
            if (y1 * my > 0) {
                y1 = my; x1 = mx;
            }
            else {
                y2 = my; x2 = mx;
            }
        }
        ret.push_back((x1 + x2) / 2);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n;
        vector<double> ans;
        vector<double> poly(n + 1);

        for (int i = 0; i <= n; i++)
            cin >> poly[i];
        
        ans = sol(poly);
        for (auto& x : ans) cout << x << " ";
        cout << '\n';
    }
    return 0;
}
