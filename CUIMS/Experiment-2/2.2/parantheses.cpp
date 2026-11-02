
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(int open, int close, int n,
              string current, vector<string>& result) {

    // Base condition
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // Add opening parenthesis
    if (open < n) {
        generate(open + 1, close, n, current + "(", result);
    }

    // Add closing parenthesis
    if (close < open) {
        generate(open, close + 1, n, current + ")", result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generate(0, 0, n, "", result);
    return result;
}

int main() {
    int n;

    cout << "Enter number of pairs: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input";
        return 0;
    }

    vector<string> result = generateParenthesis(n);

    cout << "Valid Parentheses Combinations:\n";

    for (const string& s : result) {
        cout << s << endl;
    }

    cout << "Total combinations: " << result.size() << endl;

    return 0;
}
