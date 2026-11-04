#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> result;

    for (int i = 0; i <= nums.size() - k; i++) {
        vector<int> window;

        for (int j = i; j < i + k; j++) {
            window.push_back(nums[j]);
        }

        sort(window.begin(), window.end());

        if (k % 2 == 1) {
            result.push_back(window[k / 2]);
        } else {
            double median = ((double)window[k / 2 - 1]
                           + window[k / 2]) / 2.0;
            result.push_back(median);
        }
    }

    return result;
}

int main() {
    int n, k;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    if (k <= 0 || k > n) {
        cout << "Invalid window size";
        return 0;
    }

    vector<double> result = medianSlidingWindow(nums, k);

    cout << "Sliding Window Median: ";
    for (double x : result) {
        cout << x << " ";
    }

    return 0;
}
