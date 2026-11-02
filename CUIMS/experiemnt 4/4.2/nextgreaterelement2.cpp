
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {

    int n = nums.size();

    vector<int> result(n, -1);

    stack<int> st;

    // Traverse the circular array twice
    for (int i = 0; i < 2 * n; i++) {

        while (!st.empty() &&
               nums[st.top()] < nums[i % n]) {

            result[st.top()] = nums[i % n];

            st.pop();
        }

        // Push indices only during first traversal
        if (i < n) {
            st.push(i);
        }
    }

    return result;
}

int main() {

    int n;

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

    vector<int> result = nextGreaterElements(nums);

    cout << "Next Greater Elements: [";

    for (int i = 0; i < n; i++) {

        cout << result[i];

        if (i != n - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}
