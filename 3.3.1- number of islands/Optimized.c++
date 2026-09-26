#include <bits/stdc++.h>
using namespace std;

int m, n;

void dfs(vector<vector<char>>& grid, int r, int c)
{
    // Boundary check and water check
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1')
        return;

    // Mark the cell as visited
    grid[r][c] = '0';

    // Visit Up
    dfs(grid, r - 1, c);

    // Visit Down
    dfs(grid, r + 1, c);

    // Visit Left
    dfs(grid, r, c - 1);

    // Visit Right
    dfs(grid, r, c + 1);
}

int main()
{
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    // Input grid
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int count = 0;

    // Traverse the grid
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == '1')
            {
                // Sink the complete island
                dfs(grid, r, c);

                // Count the island
                count++;
            }
        }
    }

    cout << "Number of Islands: " << count << endl;

    return 0;
}