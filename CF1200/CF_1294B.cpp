// [Tag]
// #lev2 #아이디어

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

template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T,vector<T>,greater<T> >;


template<class T>
ostream& operator << (ostream &os,const vector<T> &vec){
  for(int i=0;i<vec.size();i++){
    os << vec[i];
    if(i+1<vec.size())os << ' ';
  }
  return os;
}
template<class T>
istream& operator >> (istream &is,vector<T>& vec){
  for(int i=0;i<vec.size();i++)is >> vec[i];
  return is;
}


/*************************************************/

int T, N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    /*INPUT*/
    cin >> T;

    /*Get_Answer*/
    while (T--) {
        vector<pii> B(2001, { 0, 0 });
        //int B[1001][1001]{}; //Board
        bool ok(true);
        int mx(-1);
        cin >> N;
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            if (B[x + y] == pii{ 0, 0 }) {
                if (mx < x + y) mx = x + y;
                B[x + y] = pii{ x, y };
            }
            else ok = false;
        }
        if (!ok) { cout << "NO\n"; continue; }

        pii here = { 0, 0 };
        string ans;
        for (int i = 1; i <= mx; i++) {
            if (B[i] == pii{ 0, 0 }) continue;
            else {
                int R = B[i].first - here.first;
                int U = B[i].second - here.second;
                if (R < 0 || U < 0) { ok = false; break; }
                while (R--) ans += 'R';
                while (U--) ans += 'U';
                here.first = B[i].first;
                here.second = B[i].second;
            }
        }

        if (ok) cout << "YES\n" << ans << '\n';
        else cout << "NO\n";

    }
    return 0;
}
