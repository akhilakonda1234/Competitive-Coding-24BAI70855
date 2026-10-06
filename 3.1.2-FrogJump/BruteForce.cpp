#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int solve(int i, vector<int>& height, int k) {
    if (i == 0)
        return 0;

    int best = INT_MAX;

    for (int j = max(0, i - k); j < i; j++) {
        int cost = solve(j, height, k)
                   + abs(height[i] - height[j]);

        best = min(best, cost);
    }

    return best;
}

int main() {
    int n, k;

    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++)
        cin >> height[i];

    cout << "Enter maximum jump distance k: ";
    cin >> k;

    cout << "Minimum cost = "
         << solve(n - 1, height, k) << endl;

    return 0;
}
