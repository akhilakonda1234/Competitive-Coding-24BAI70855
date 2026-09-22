#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& candidates, int target,
           vector<int>& current,
           set<vector<int>>& result) {

    if (target == 0) {
        vector<int> temp = current;
        sort(temp.begin(), temp.end());
        result.insert(temp);
        return;
    }

    if (target < 0)
        return;

    for (int x : candidates) {
        current.push_back(x);

        solve(candidates, target - x, current, result);

        current.pop_back();
    }
}

int main() {

    vector<int> candidates = {4, 3, 4, 7};
    int target = 9;

    vector<int> current;
    set<vector<int>> result;

    solve(candidates, target, current, result);

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
