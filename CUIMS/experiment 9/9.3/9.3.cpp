#include <iostream>
#include <vector>
using namespace std;

int n;

vector<vector<int>> adj;
vector<int> cnt, ans;

// First DFS
void dfs1(int u, int parent) {
    cnt[u] = 1;

    for (int v : adj[u]) {
        if (v == parent)
            continue;

        dfs1(v, u);

        cnt[u] += cnt[v];
        ans[0] += cnt[v];
    }
}

// Second DFS
void dfs2(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent)
            continue;

        ans[v] = ans[u] - cnt[v] + (n - cnt[v]);

        dfs2(v, u);
    }
}

int main() {
    int e;

    cout << "Enter number of nodes: ";
    cin >> n;

    adj.resize(n);
    cnt.assign(n, 0);
    ans.assign(n, 0);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges:\n";

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n > 0) {
        dfs1(0, -1);
        dfs2(0, -1);
    }

    cout << "Sum of distances: ";

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
