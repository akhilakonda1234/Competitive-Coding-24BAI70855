#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited,
         int current, int destination) {

    if (current == destination)
        return true;

    visited[current] = true;

    for (int next : adj[current]) {

        if (!visited[next]) {

            if (dfs(adj, visited, next, destination))
                return true;
        }
    }

    return false;
}

bool validPath(int n, vector<vector<int>>& edges,
               int source, int destination) {

    // Build adjacency list
    vector<vector<int>> adj(n);

    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);

    return dfs(adj, visited, source, destination);
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