#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcsBruteForce(string text1, string text2, int i, int j) {
    if (i == text1.length() || j == text2.length())
        return 0;

    if (text1[i] == text2[j]) {
        return 1 + lcsBruteForce(text1, text2, i + 1, j + 1);
    }

    return max(
        lcsBruteForce(text1, text2, i + 1, j),
        lcsBruteForce(text1, text2, i, j + 1)
    );
}

int main() {
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;

    cout << "Enter second string: ";
    cin >> text2;

    int result = lcsBruteForce(text1, text2, 0, 0);

    cout << "Length of LCS = " << result << endl;

    return 0;
}
