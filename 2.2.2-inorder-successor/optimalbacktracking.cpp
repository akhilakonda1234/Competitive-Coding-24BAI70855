#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& candidates, int start,
               vector<int>& current, int remaining,
               vector<vector<int>>& result)
{
    if(remaining == 0)
    {
        result.push_back(current);
        return;
    }

    for(int i = start; i < candidates.size(); i++)
    {
        if(candidates[i] > remaining)
            continue;

        current.push_back(candidates[i]);

        // Use i again because repetition is allowed
        backtrack(candidates, i, current,
                  remaining - candidates[i], result);

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

    sort(candidates.begin(), candidates.end());

    vector<int> current;
    vector<vector<int>> result;

    backtrack(candidates, 0, current, target, result);

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
