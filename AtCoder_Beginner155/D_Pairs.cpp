#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
#define ALL(vec) begin(vec), end(vec)
typedef long long i64;
template<typename T> inline bool uax(T &x, T y) {return (y > x) ? x = y, true : false;}
template<typename T> inline bool uin(T &x, T y) {return (y < x) ? x = y, true : false;}
#ifdef Rahul
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
  stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#else
#define error(...) 42;
#endif
string to_string(char c) { return "'" + string(1, c) + "'";}
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
template<typename A> string to_string(A);
template<typename A, typename B> string to_string(pair<A, B> p){
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";}
template<typename A> string to_string(A v) {bool f = false; string r = "{"; 
  for (auto x: v) {if (f) r += ", "; r += to_string(x); f = true;} return r += "}";}
template<typename A> string to_string(vector<vector<A>> v) {string r; 
  for (auto x: v) r += "\n" + to_string(x); return r;}
int Nerr;
template<typename A> string to_string(A *p) {return to_string(vector<A>(p, p + Nerr));}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << "; "; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
int const MOD = 1e9 + 7;
long long const INF = 1e18 + 42;
/***********************************************************************/
 
int32_t main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  
  i64 n, k;
  cin >> n >> k;
  i64 zer = 0;
  vector<i64> pos, neg;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    zer += x == 0;
    if (x > 0) pos.push_back(x);
    if (x < 0) neg.push_back(-x);
  }
  sort(ALL(pos));
  sort(ALL(neg));
  auto cnt = [&] (i64 x) {
    if (x == 0) {
      return (i64) SZ(pos) * SZ(neg);
    }
    i64 res = 0;
    if (x > 0) {
      res = (i64) SZ(pos) * SZ(neg);
      res += (i64) zer * (n - zer);
      res += (i64) zer * (zer - 1) / 2;
      int r = 0;
      for (int i = SZ(pos) - 1; i >= 0; --i) {
        while (r < i && pos[r] * pos[i] < x) {
          ++r;
        }
        res += min(i, r);
      }
      r = 0;
      for (int i = SZ(neg) - 1; i >= 0; --i) {
        while (r < i && neg[r] * neg[i] < x) {
          ++r;
        }
        res += min(i, r);
      }
    } else {
      int r = SZ(neg) - 1;
      for (int i = 0; i < SZ(pos); ++i) {
        while (r >= 0 && pos[i] * neg[r] > -x) {
          --r;
        }
        res += SZ(neg) - r - 1;
      }
    }
    return res;
  }; 
  i64 lo = -INF, hi = INF;
  while (lo < hi) {
    i64 md = lo + (hi - lo + 1) / 2;
    if (cnt(md) >= k) hi = md - 1;
    else lo = md;
  }
  cout << lo << '\n';
}

/////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	using ll = long long;
	ll k; cin >> k;
	const ll inf = 1ll<<60;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	ll lo = -inf, hi = inf, ans = 0;
	while(lo <= hi){
		ll mid = (lo + hi)>>1, cnt = 0;
		for(int i = 0; i < n; i++){
			if(a[i] < 0){
				int Lo = 0, Hi = n - 1, Ans = n;
				while(Lo <= Hi){
					int Mid = (Lo + Hi)>>1;
					if(a[Mid] * a[i] <= mid) Hi = Mid - 1, Ans = Mid;
					else Lo = Mid + 1;
				}
				cnt += n - Ans;
			} else {
				int Lo = 0, Hi = n - 1, Ans = -1;
				while(Lo <= Hi){
					int Mid = (Lo + Hi)>>1;
					if(a[Mid] * a[i] <= mid) Lo = Mid + 1, Ans = Mid;
					else Hi = Mid - 1;
				}
				cnt += Ans + 1;
			}
			if(a[i] * a[i] <= mid) cnt--;
		}
		cnt /= 2;
		if(cnt >= k) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
