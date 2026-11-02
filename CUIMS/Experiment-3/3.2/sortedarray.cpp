
#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {

    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // Target found
        if (nums[mid] == target)
            return true;

        // Handle duplicates
        if (nums[low] == nums[mid] &&
            nums[mid] == nums[high]) {

            low++;
            high--;
        }

        // Left half is sorted
        else if (nums[low] <= nums[mid]) {

            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        // Right half is sorted
        else {

            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return false;
}

int main() {

    int n, target;

    cout << "Enter array size: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid array size";
        return 0;
    }

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target element: ";
    cin >> target;

    if (search(nums, target))
        cout << "Target found: true";
    else
        cout << "Target found: false";

    return 0;
}
