
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {

    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {

        int mid = low + (high - low) / 2;

        // Minimum is in the right half
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        }

        // Minimum is in the left half
        else if (nums[mid] < nums[high]) {
            high = mid;
        }

        // Handle duplicate elements
        else {
            high--;
        }
    }

    return nums[low];
}

int main() {

    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size";
        return 0;
    }

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Minimum element: " << findMin(nums);

    return 0;
}
