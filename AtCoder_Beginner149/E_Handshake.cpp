// [Tag]
// #lev4 #BinarySearch

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

constexpr int               inf = 2123456789;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;

template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T, vector<T>, greater<T> >;


template<class T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i + 1 < vec.size())os << ' ';
    }
    return os;
}
template<class T>
istream& operator >> (istream& is, vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++)is >> vec[i];
    return is;
}


/*************************************************/
ll M;
vl Sum;
int N;
vi A;

ll solve(int mid) {
	//Pair합이 mn이상인 짝이 몇개인지 반환하는 함수.
	int p2 = N - 1;
	ll cnt = 0;
	//ll n_if(0);
	for (int p1 = 0; p1 < N; p1++) {
		while (p2 >= 0 && A[p1] + A[p2] < mid) p2--;
		cnt += p2 + 1;
	}
	//cout << "count by " << n_if << "\n";
 	return cnt;
}

ll calc(int mid) {
	int p2 = N - 1;
	ll cnt = 0;
	ll ans = 0;

	for (int p1 = 0; p1 < N; p1++) {
		while (p2 >= 0 && A[p1] + A[p2] <= mid) p2--;
		if (p2 >= 0) {
			ans += Sum[p2] + 1LL * (p2 + 1) * A[p1];
		}
		cnt += p2 + 1;
	}
	ans += 1LL * (M - cnt) * mid;
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    /*INPUT*/
    cin >> N >> M;
    A.resize(N);
    Sum.resize(N + 1);
    for (auto& a : A)
        cin >> a;

	sort(A.begin(), A.end(), greater<int>());
    Sum[0] = A[0];
    for (int i = 1; i < N; i++)
        Sum[i] = Sum[i - 1] + A[i];

	int lb = 0;         //lower bound
	int ub = 2e5 + 1;   //upper bound
	//int d = 1;
	while (ub - lb > 1) {   
        //lb == ub가 되는 순간을 찾는다.
        //이 때의 lb는 M개의 짝을 찾게 되는 순간의 Pair합이다.
		//cout << d << "-th mid : "; d++;
		int mid = (lb + ub) / 2;
		//cout << mid << ".\n";
		if (solve(mid) >= M) lb = mid;
		else ub = mid;
	}

	cout << calc(lb) << '\n';
    return 0;
}
