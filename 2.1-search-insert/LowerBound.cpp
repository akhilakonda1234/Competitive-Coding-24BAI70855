#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums,int target)
{
    int left=0;
    int right=nums.size()-1;
    int ans=nums.size();
    while(left<=right)
    {
        int mid=(left+right)/2;

        if(nums[mid]>=target)
        {
            ans=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter sorted elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int target;
    cout<<"Enter target: ";
    cin>>target;
    cout<<"Position = " << searchInsert(nums, target);
    return 0;
}
