#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target)
{
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    int ans = search(nums, target);

    cout << "Index = " << ans;

    return 0;
}
