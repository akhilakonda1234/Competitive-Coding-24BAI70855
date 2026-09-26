#include <bits/stdc++.h>
using namespace std;

int m, n;

void dfs(vector<vector<char>>& grid,
         vector<vector<bool>>& visited,
         int r, int c) {

    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    if (visited[r][c] || grid[r][c] == '0')
        return;

    visited[r][c] = true;

    dfs(grid, visited, r - 1, c);
    dfs(grid, visited, r + 1, c);
    dfs(grid, visited, r, c - 1);
    dfs(grid, visited, r, c + 1);
}

int main() {

    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(
        m, vector<bool>(n, false)
    );

    int count = 0;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {

            if (grid[r][c] == '1' && !visited[r][c]) {

                dfs(grid, visited, r, c);

                count++;
            }
        }
    }

    cout << "Number of Islands: " << count << endl;

    return 0;
}