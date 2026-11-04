#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> parent, rank_;

    DSU(int n) {
        parent.resize(n + 1);
        rank_.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;

        if (rank_[u] < rank_[v]) {
            swap(u, v);
        }

        parent[v] = u;

        if (rank_[u] == rank_[v]) {
            rank_[u]++;
        }

        return true;
    }
};

vector<int> findRedundantDirectedConnection(
    vector<vector<int>>& edges) {

    int n = edges.size();

    vector<int> parent(n + 1, 0);
    vector<int> cand1, cand2;

    // Step 1: Find a node with two parents
    for (auto& e : edges) {
        if (parent[e[1]] == 0) {
            parent[e[1]] = e[0];
        } else {
            cand1 = {parent[e[1]], e[1]};
            cand2 = e;
        }
    }

    // Step 2: Apply Union-Find
    DSU dsu(n);

    for (auto& e : edges) {

        // Skip the second candidate edge
        if (!cand2.empty() && e == cand2) {
            continue;
        }

        if (!dsu.unite(e[0], e[1])) {

            // Cycle detected
            if (cand1.empty()) {
                return e;
            }

            return cand1;
        }
    }

    // No cycle after skipping cand2
    return cand2;
}

int main() {
    int n;

    cout << "Enter number of edges: ";
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2));

    cout << "Enter directed edges (u v):\n";

    for (int i = 0; i < n; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = findRedundantDirectedConnection(edges);

    cout << "Redundant edge: ["
         << result[0] << "," << result[1] << "]";

    return 0;
}
