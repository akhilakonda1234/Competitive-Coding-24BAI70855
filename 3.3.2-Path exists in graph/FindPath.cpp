#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

    vector<vector<int>> adj(n);

    // Build adjacency list
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    if (source == destination)
        return true;

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;

    // BFS
    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (int next : adj[node]) {

            if (next == destination)
                return true;

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
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

    bool result = validPath(n, edges, source, destination);

    cout << (result ? "true" : "false") << endl;

    return 0;
}