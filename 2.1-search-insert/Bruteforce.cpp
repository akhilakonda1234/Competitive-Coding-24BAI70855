#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target)
{
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        if(nums[i]>=target)
        {
            return i;
        }
    }
    return n;
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
    int index=searchInsert(nums,target);
    cout<<"Position= "<<index;
    return 0;
}
