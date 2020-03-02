/* #lev3 #Kruskal #Greedy            */

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
struct OptimizedDisjointSet {
    vector<int> parent, rank;
    OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u]) return u;

        // 경로 압축 (path compression)
        // parent 를 찾아낸 루트로 아예 바꿔 버리면
        // find 연산 수행시 중복되는 연산을 줄여준다.
        // ( 다음번 동일한 find 연산 수행시 경로를 따라 올라갈 필요 없이 바로 
        // 루트를 찾을 수 있게 된다. )
        // 재귀적인 구현 덕분에 u 에서 루트까지 올라가는 경로 상에 있는
        // 모든 노드들에게도 경로 압축 최적화가 자동으로 수행된다. 
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);

        if (u == v) return;

        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        //두 트리의 높이가 같은 경우에는 결과 트리의 rank 를 1 높혀준다.
        if (rank[u] == rank[v]) ++rank[v];
    }
};

int n, m, k;
vi ans, chk;
vi W;
void sol() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    W.assign(n + 1, 0);
    chk.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    OptimizedDisjointSet uf(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        uf.merge(a, b);
        W[a]++, W[b]++;
    }

    for (int i = 1; i <= n; i++)
        chk[uf.find(i)]++;

    for (int i = 1; i <= n; i++)
        ans[i] = chk[uf.find(i)] - W[i] - 1;
        
    for (int i = 0; i < k; i++) {
        int c, d; cin >> c >> d;
        if (uf.find(c) == uf.find(d)) {

            ans[c]--; ans[d]--;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
