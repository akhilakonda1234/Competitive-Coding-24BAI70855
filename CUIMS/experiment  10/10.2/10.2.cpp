#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> color(n, -1);

    for (int start = 0; start < n; start++) {

        if (color[start] != -1)
            continue;

        queue<int> q;

        q.push(start);
        color[start] = 0;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (int v : graph[u]) {

                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {

        int k;

        cout << "Enter number of neighbours of vertex " << i << ": ";
        cin >> k;

        cout << "Enter neighbours: ";

        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            graph[i].push_back(v);
        }
    }

    cout << "Is Bipartite: "
         << (isBipartite(graph) ? "true" : "false");

    return 0;
}
