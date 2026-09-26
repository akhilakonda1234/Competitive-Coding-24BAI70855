#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int r, int c) {

    int m = grid.size();
    int n = grid[0].size();

    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
        return;

    // Mark as visited
    grid[r][c] = 0;

    // Four directions
    dfs(grid, r - 1, c); // Up
    dfs(grid, r + 1, c); // Down
    dfs(grid, r, c - 1); // Left
    dfs(grid, r, c + 1); // Right
}

int numIslands(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1) {

                count++;

                dfs(grid, i, j);
            }
        }
    }

    return count;
}

int main() {

    int m, n;

    cout << "Enter number of rows: ";
    cin >> m;

    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Number of islands: " << numIslands(grid) << endl;

    return 0;
}