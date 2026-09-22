#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, int start, vector<int>& current)
{
    cout << "{ ";

    for(int x : current)
    {
        cout << x << " ";
    }

    cout << "}\n";

    for(int i = start; i < nums.size(); i++)
    {
        current.push_back(nums[i]);

        backtrack(nums, i + 1, current);

        current.pop_back();
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> current;

    cout << "\nAll Subsets:\n";

    backtrack(nums, 0, current);

    return 0;
}
