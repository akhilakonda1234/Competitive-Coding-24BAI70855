
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find maximum subsequence of given length
vector<int> maxSubseq(vector<int>& nums, int len) {

    int drop = nums.size() - len;
    vector<int> st;

    for (int x : nums) {

        while (drop > 0 && !st.empty() && st.back() < x) {
            st.pop_back();
            drop--;
        }

        st.push_back(x);
    }

    st.resize(len);

    return st;
}

// Merge two subsequences
vector<int> merge(vector<int>& a, vector<int>& b) {

    vector<int> result;

    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {

        if (lexicographical_compare(
                b.begin() + j, b.end(),
                a.begin() + i, a.end())) {

            result.push_back(a[i++]);
        }
        else {
            result.push_back(b[j++]);
        }
    }

    while (i < a.size())
        result.push_back(a[i++]);

    while (j < b.size())
        result.push_back(b[j++]);

    return result;
}

// Compare two results
bool greaterNumber(vector<int>& a, vector<int>& b) {
    return lexicographical_compare(
        b.begin(), b.end(), a.begin(), a.end());
}

// Create maximum number of length k
vector<int> maxNumber(vector<int>& nums1,
                      vector<int>& nums2, int k) {

    int m = nums1.size();
    int n = nums2.size();

    vector<int> best;

    for (int i = max(0, k - n); i <= min(k, m); i++) {

        vector<int> s1 = maxSubseq(nums1, i);
        vector<int> s2 = maxSubseq(nums2, k - i);

        vector<int> merged = merge(s1, s2);

        if (greaterNumber(merged, best))
            best = merged;
    }

    return best;
}

int main() {

    int m, n, k;

    cout << "Enter size of first array: ";
    cin >> m;

    vector<int> nums1(m);

    cout << "Enter first array elements: ";

    for (int i = 0; i < m; i++)
        cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> n;

    vector<int> nums2(n);

    cout << "Enter second array elements: ";

    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    cout << "Enter value of k: ";
    cin >> k;

    if (m < 0 || n < 0 || k < 0 || k > m + n) {
        cout << "Invalid input";
        return 0;
    }

    vector<int> result = maxNumber(nums1, nums2, k);

    cout << "Maximum Number: [";

    for (int i = 0; i < result.size(); i++) {

        cout << result[i];

        if (i != result.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;

    return 0;
}
