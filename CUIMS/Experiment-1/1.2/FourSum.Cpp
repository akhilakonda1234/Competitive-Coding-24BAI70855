#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    sort(nums.begin(), nums.end());

    cout << "Quadruplets are:" << endl;

    bool found = false;

    for (int i = 0; i < n - 3; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++) {

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right) {

                long long sum = (long long)nums[i]
                              + nums[j]
                              + nums[left]
                              + nums[right];

                if (sum == target) {

                    cout << "["
                         << nums[i] << ","
                         << nums[j] << ","
                         << nums[left] << ","
                         << nums[right] << "]"
                         << endl;

                    found = true;

                    while (left < right &&
                           nums[left] == nums[left + 1])
                        left++;

                    while (left < right &&
                           nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    if (!found) {
        cout << "No quadruplets found." << endl;
    }

    return 0;
}
