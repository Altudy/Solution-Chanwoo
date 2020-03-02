// 최적화된 서로소 집합 Struct 구현. == Union_Find set
typedef struct OptimizedDisjointSet {
    vector<int> parent, rank;
    OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u]) return u; //경로압축
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
}ODS;
