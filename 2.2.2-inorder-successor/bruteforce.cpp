#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;

void solve(vector<int>& candidates, int target, vector<int>& current)
{
    if(target == 0)
    {
        sort(current.begin(), current.end());

        // Check if combination already exists
        if(find(result.begin(), result.end(), current) == result.end())
            result.push_back(current);

        return;
    }

    if(target < 0)
        return;

    for(int i = 0; i < candidates.size(); i++)
    {
        current.push_back(candidates[i]);

        solve(candidates, target - candidates[i], current);

        current.pop_back();
    }
}

int main()
{
    int n, target;

    cout << "Enter number of candidates: ";
    cin >> n;

    vector<int> candidates(n);

    cout << "Enter candidates: ";
    for(int i = 0; i < n; i++)
        cin >> candidates[i];

    cout << "Enter target: ";
    cin >> target;

    vector<int> current;

    solve(candidates, target, current);

    cout << "\nCombinations:\n";

    for(auto combination : result)
    {
        cout << "[ ";
        for(int x : combination)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
