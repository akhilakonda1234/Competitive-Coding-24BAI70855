#include <iostream>
#include <vector>
using namespace std;

class DSU {

private:
    vector<int> parent;
    vector<int> rankValue;

public:

    DSU(int n) {

        parent.resize(n);
        rankValue.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {

        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y) {

        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rankValue[rootX] < rankValue[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rankValue[rootX] > rankValue[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rankValue[rootX]++;
        }
    }
};

bool validPath(int n, vector<vector<int>>& edges,
               int source, int destination) {

    DSU dsu(n);

    // Union all connected nodes
    for (auto& edge : edges) {
        dsu.unite(edge[0], edge[1]);
    }

    // Check whether source and destination
    // belong to the same component
    return dsu.find(source) == dsu.find(destination);
}

int main() {

    int n, m;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter edges:\n";

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int source, destination;

    cout << "Enter source: ";
    cin >> source;

    cout << "Enter destination: ";
    cin >> destination;

    if (validPath(n, edges, source, destination))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}