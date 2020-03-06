#include <iostream>
using namespace std;

typedef vector<int> vi;

const int INT_MAX = numeric_limits<int>::max();

struct RMQ // (Range Minimum Query 구간최소쿼리)
{
	// the length of array
	int n;

	// min value of the given range.
	vi rangeMin;

	// Constructor
	RMQ(const vi& array){
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n-1, 1);
	}

	// recursively fill array by Bottom-Up style.
	int init(const vi& array, int l, int r, int node){
		if(l == r)
			return rangeMin[node] = array[l]; // == array[r].
		int mid = (l + r)/2;
		int l_min = init(array, l, mid, node*2);
		int r_min = init(array, mid+1, r, node*2);
		return rangeMin[node] = min(l_min, r_min);
	}

	int query(int l, int r, int node, int node_l, int node_r){
		//if intersection doesn't exist, return MAX.
		if(r < node_l || node_r < l) return INT_MAX;

		if(l <= node_l && r >= node_r) return rangeMin[node];

		int mid = (node_l + node_r) / 2;
		//구간 [l, r]을 쪼개는 것이 아니라 init과 같이 node_l, node_r을
		//쪼개어 가며, 답을 찾는다. -> 빠르게 구간을 모을 수 있음.
		return min(query(l, r, node*2, node_l, mid),
					query(l, r, node*2, mid+1, node_r));
	}

	// for external call
	int query(int l, int r){
		return query(l, r, 1, 0, n-1);
	}

	int update(int idx, int n_val, int node, int node_l, int node_r){
		// if not related, ignore.
		if(idx < node_l || node_r < idx) return rangeMin[node];

		// if leaf node.
		if(node_l == node_r) return rangeMin[node] = n_val;

		int mid = (node_l _ node_r)/2;
		return rangeMin[node] = min(
				update(idx, n_val, node*2, node_l, mid),
				update(idx, n_val, node*2 + 1, mid+1, node_r) );
	}

	int update(int idx, int n_val){
		return update(idx, n_val, 1, 0, n-1);
	}
};


//숫자의 최대 출현 횟수 문제의 두 개의 답을 합치기.
struct Block {
	int sz;
	int mostFreq;
	int num_l, num_r;
	int freq_l, freq_r;
};

// 위 코드처럼, node_l, node_r을 쪼개어 계산하다 보면, merge가 쓰일수 있다.
Block merge(const Block& a, const Block& b){
	Block ret;

	ret.size = a.size + b.size;

	//========================================
	// ret를 Block의 맥락에 맞게 갱신해주는 작업.
	ret.num_l = a.num_l;
	ret.freq_l = a.freq_l;
	if(a.sz == a.freq_l && a.num_l == b.num_l)
		ret.freq_l += b.freq_l;

	ret.num_r = b.num_r;
	ret.freq_r = b.freq_r;
	if(b.sz == b.freq_r && a.num_r == b.num_r)
		ret.freq_r += a.freq_r;
	//========================================

	ret.mostFreq = max(a.mostFreq, b.mostFreq);
	// 맞닿는 부분이 같은 숫자일 경우 반영해준다.
	if(a.num_r == b.num_r)
		ret.mostFreq = max(ret.mostFreq, a.freq_r + b.freq_l);

	return ret;
}

