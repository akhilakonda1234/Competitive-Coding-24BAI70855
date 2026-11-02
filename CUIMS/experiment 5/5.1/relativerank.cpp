
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Assign relative ranks to athletes
vector<string> findRelativeRanks(vector<int>& score) {

    int n = score.size();

    unordered_map<int, int> indexMap;

    // Store original positions
    for (int i = 0; i < n; i++) {
        indexMap[score[i]] = i;
    }

    // Sort scores in descending order
    vector<int> sorted = score;

    sort(sorted.begin(), sorted.end(), greater<int>());

    vector<string> result(n);

    // Assign medals and positions
    for (int i = 0; i < n; i++) {

        int originalIndex = indexMap[sorted[i]];

        if (i == 0)
            result[originalIndex] = "Gold Medal";

        else if (i == 1)
            result[originalIndex] = "Silver Medal";

        else if (i == 2)
            result[originalIndex] = "Bronze Medal";

        else
            result[originalIndex] = to_string(i + 1);
    }

    return result;
}

int main() {

    int n;

    cout << "Enter number of athletes: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input";
        return 0;
    }

    vector<int> score(n);

    cout << "Enter athlete scores: ";

    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    vector<string> result = findRelativeRanks(score);

    cout << "Relative Ranks: ";

    for (string s : result) {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}
