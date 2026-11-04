#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int longestSubstring(string s, int k) {

    if (s.size() == 0 || s.size() < k) {
        return 0;
    }

    vector<int> freq(26, 0);

    // Count character frequencies
    for (char ch : s) {
        freq[ch - 'a']++;
    }

    // Divide the string
    for (int i = 0; i < s.size(); i++) {

        if (freq[s[i] - 'a'] < k) {

            int left = longestSubstring(s.substr(0, i), k);

            int right = longestSubstring(s.substr(i + 1), k);

            return max(left, right);
        }
    }

    return s.size();
}

int main() {
    string s;
    int k;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    cout << "Longest Substring Length: "
         << longestSubstring(s, k);

    return 0;
}
