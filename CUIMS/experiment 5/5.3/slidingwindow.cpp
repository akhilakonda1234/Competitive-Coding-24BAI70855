
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Find maximum element in every sliding window
vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    vector<int> result;

    deque<int> dq;  // Stores indices

    for (int i = 0; i < nums.size(); i++) {

        // Remove indices outside the current window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove smaller elements from the back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // Insert current index
        dq.push_back(i);

        // Store maximum after forming a complete window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {

    int n, k;

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

    cout << "Enter window size: ";
    cin >> k;

    if (k <= 0 || k > n) {
        cout << "Invalid window size";
        return 0;
    }

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximum: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
