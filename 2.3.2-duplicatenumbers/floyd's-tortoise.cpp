#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums)
{
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Find meeting point
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

    } while(slow != fast);

    // Phase 2: Find cycle entrance
    slow = nums[0];

    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
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
