#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& grid, int r, int c) {

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;

    q.push({r, c});

    // Mark as visited
    grid[r][c] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {

        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        // Check 4 directions
        for (int i = 0; i < 4; i++) {

            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                grid[nr][nc] == 1) {

                grid[nr][nc] = 0;

                q.push({nr, nc});
            }
        }
    }
}

int numIslands(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1) {

                count++;

                bfs(grid, i, j);
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