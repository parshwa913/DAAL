#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& parent, int u) {
    if (parent[u] != u)
        parent[u] = find(parent, parent[u]);
    return parent[u];
}

void union_sets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int root_u = find(parent, u);
    int root_v = find(parent, v);
    
    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v])
            parent[root_v] = root_u;
        else if (rank[root_u] < rank[root_v])
            parent[root_u] = root_v;
        else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

bool is_balanced(vector<int>& rail_parent, vector<int>& road_parent, int u, int v) {
    return find(rail_parent, u) == find(rail_parent, v) &&
           find(road_parent, u) == find(road_parent, v);
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> rail_parent(n + 1), road_parent(n + 1), rail_rank(n + 1, 0), road_rank(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        rail_parent[i] = i;
        road_parent[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            union_sets(rail_parent, rail_rank, u, v);
        } else {
            union_sets(road_parent, road_rank, u, v);
        }

        if (is_balanced(rail_parent, road_parent, u, v)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
