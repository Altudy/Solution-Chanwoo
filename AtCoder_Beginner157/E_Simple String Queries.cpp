/* #                          */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include <map>
#include <iomanip>
#include <functional>
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
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/
template <typename M>
struct SegTree {
    using Op = function<M(const M&, const M&)>;
    M ID;   // monoid identity
    Op op;  // associative operation
    int N;  // 2^lg space, for non-commutative
    vector<M> a;

    SegTree(int n, M leaf_default, M _ID, Op _op) : ID(_ID), op(_op) {
        init_space(n);
        fill(a.begin() + N, a.begin() + N + n, leaf_default);
        build();
    }

    SegTree(const vector<M> leaves, M _ID, Op _op) : ID(_ID), op(_op) {
        int n = leaves.size();  // array size
        init_space(n);          // Initialize Segment Tree by ID(0)
        copy(leaves.begin(), leaves.end(), a.begin() + N);
        build();                // Build up Segment Tree.
    }

    void init_space(int n) {
        N = 1; while (N < n) N <<= 1; // assign array space
        a.assign(N << 1, ID);         // 0으로 초기화
    }

    inline void pull(int i) { a[i] = op(a[i << 1], a[i << 1 | 1]); }
    void build() { for (int i = N - 1; i >= 1; i--) pull(i); }

    //Update
    void assign(int p, M val) {
        assert(0 <= p && p < N);
        for (a[p += N] = val; p >>= 1;) pull(p);
    }

    //Query
    M query(int l, int r) const {
        assert(0 <= l && r <= N);
        M resl(ID), resr(ID);
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = op(resl, a[l++]);
            if (r & 1) resr = op(a[--r], resr);
        }
        return op(resl, resr);
    }
    M query_point(int p) const {
        assert(0 <= p && p < N);
        return a[p + N];
    }
    M query_all() const { return a[1]; }
};

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = 1 << (s[i] - 'a'); // transform to [0, 25].
    }

    SegTree<int> occur(a, 0, [](int u, int v) { return u | v; });

    int q; cin >> q; //the number of quries.
    while (q--) {
        int op; cin >> op;
        if (op == 1) { //change i-th character.
            int i; char x;
            cin >> i >> x;
            i--;
            occur.assign(i, 1 << (x - 'a'));
        }
        else {  //the number of different characters in [l, r].
            int l, r;
            cin >> l >> r;
            l--;
            cout << __builtin_popcount(occur.query(l, r)) << '\n';
        }
    }
}

int OR(const int& x, const int& y){
    return x|y;
}

int bitCount(const int& x){
    if(x == 0)  return 0;
    else        return (x&1) + bitCount(x>>1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

//

#include <bits/stdc++.h>
using namespace std;
 
template<typename M>
struct segment_tree{
    typedef function<M(M, M)> F;
    int size;//2冪
    vector<M> val;//1-indexed
    F f;//結合関数
    M e;//単位元
 
    segment_tree(int N, vector<M> &data, F f, M e) : f(f), e(e){
        size = 1;
        while(size < N) size *= 2;
        val.assign(2 * size, e);
        for(int i = 0; i < N; i++) val[size + i] = data[i];
        for(int i = N; i < size; i++) val[size + i] = e;
        for(int i = size - 1; i > 0; i--) val[i] = f(val[2 * i], val[2 * i + 1]);
    }
 
    //k番目の要素をxに変更する
    void update(int k, M x){
        k += size;
        val[k] = x;
        while(k /= 2) val[k] = f(val[2 * k], val[2 * k + 1]);
    }
 
    //[l, r)の演算の結果を返す
    M query(int l, int r){
        M L = e, R = e;
        for(l += size, r += size; l < r; l /= 2, r /= 2){
            if(l & 1) L = f(L, val[l++]);
            if(r & 1) R = f(val[--r], R);
        }
        return f(L, R);
    }
};
 
 
 
 
//(int, sum, 0)
int my_or(int x, int y){
    return x | y;
}
 
int bit_count(int x){
    if(x == 0){
        return 0;
    }
    else{
        return (x & 1) + bit_count(x >> 1);
    }
}
 
int main(){
    int N, Q;
    scanf("%d", &N);
    string S;
    cin >> S;
    vector<int> data(N, 0);
    for(int i = 0; i < N; i++){
        data[i] = (1 << (S[i] - 'a'));
    }
    segment_tree<int> t(N, data, my_or, 0);
    scanf("%d", &Q);
    while(Q--){
        int type;
        scanf("%d", &type);
        if(type == 1){
            int i;
            char c;
            scanf("%d %c", &i, &c);
            i--;
            t.update(i, 1 << (c - 'a'));
        }
        else{
            int l, r;
            scanf("%d%d", &l, &r);
            l--;
            printf("%d\n", bit_count(t.query(l, r)));
        }
    }
    return 0;
}
