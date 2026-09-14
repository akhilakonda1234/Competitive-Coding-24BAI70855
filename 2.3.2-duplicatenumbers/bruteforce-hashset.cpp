#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findDuplicate(vector<int>& nums)
{
    unordered_set<int> seen;

    for(int x : nums)
    {
        if(seen.count(x))
            return x;

        seen.insert(x);
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Duplicate Number = " << findDuplicate(nums) << endl;

    return 0;
}
