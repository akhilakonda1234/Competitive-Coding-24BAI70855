#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& candidates,
               int start,
               vector<int>& current,
               int remaining,
               vector<vector<int>>& result) {

    // Target reached
    if (remaining == 0) {
        result.push_back(current);
        return;
    }

    // Try candidates from start index
    for (int i = start; i < candidates.size(); i++) {

        // Pruning
        if (candidates[i] > remaining)
            continue;

        // Choose
        current.push_back(candidates[i]);

        // Explore
        backtrack(candidates,
                  i,
                  current,
                  remaining - candidates[i],
                  result);

        // Undo choice
        current.pop_back();
    }
}

int main() {

    vector<int> candidates = {3, 3, 2, 7};
    int target = 6;

    vector<vector<int>> result;
    vector<int> current;

    backtrack(candidates, 0, current, target, result);

    cout << "Combinations:\n";

    for (auto combination : result) {
        cout << "[";

        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i];

            if (i < combination.size() - 1)
                cout << ",";
        }

        cout << "]\n";
    }

    return 0;
}
