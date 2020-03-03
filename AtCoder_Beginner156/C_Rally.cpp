// #lev1 #허무하네 #BF

/* #                          */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include <map>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
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
#define     it(x)  x.begin() 
#define     all(x)  x.begin(), x.end()
#define     pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long     INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/

int n;
int xi;

void MN(int& x, const int& y){
    if(x > y) x = y;
}
int main(){
    cin >> n;
    vector<int> X(n);
    for(auto& x : X) cin >> x;

    int sum;
    int ans = inf;

    for(int p=1; p<101; p++){ // Check every staring point. -> Brute Force
        sum = 0;
        for(int i=0; i<n; i++){
            sum += (x[i]-p)*(x[i]-p);
        }
        MN(ans, sum);
    }

    cout << ans << endl;
}
