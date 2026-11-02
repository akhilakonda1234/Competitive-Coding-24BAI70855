
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1,
                               vector<int>& nums2) {

    unordered_map<int, int> nge;
    stack<int> st;

    // Find next greater elements in nums2
    for (int num : nums2) {

        while (!st.empty() && st.top() < num) {

            nge[st.top()] = num;
            st.pop();
        }

        st.push(num);
    }

    // Elements without a greater element
    while (!st.empty()) {

        nge[st.top()] = -1;
        st.pop();
    }

    // Find answers for nums1
    vector<int> result;

    for (int num : nums1) {
        result.push_back(nge[num]);
    }

    return result;
}

int main() {

    int n, m;

    cout << "Enter size of nums1: ";
    cin >> n;

    vector<int> nums1(n);

    cout << "Enter nums1 elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of nums2: ";
    cin >> m;

    vector<int> nums2(m);

    cout << "Enter nums2 elements: ";

    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: [";

    for (int i = 0; i < result.size(); i++) {

        cout << result[i];

        if (i != result.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;

    return 0;
}
