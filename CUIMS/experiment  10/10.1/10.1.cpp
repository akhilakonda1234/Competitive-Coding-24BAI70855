#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    unordered_map<int, int> count;

    for (auto edge : edges) {
        count[edge[0]]++;
        count[edge[1]]++;
    }

    for (auto p : count) {
        if (p.second == edges.size()) {
            return p.first;
        }
    }

    return -1;
}

int main() {
    int e;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << "Center node: " << findCenter(edges);

    return 0;
}
