#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    double maxSum = -1000000000;

    for (int i = 0; i <= n - k; i++) {
        int sum = 0;

        for (int j = i; j < i + k; j++) {
            sum += nums[j];
        }

        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum / k;
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

    cout << "Maximum Average: " << findMaxAverage(nums, k);

    return 0;
}
