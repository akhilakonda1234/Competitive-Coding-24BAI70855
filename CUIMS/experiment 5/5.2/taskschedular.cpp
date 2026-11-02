
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Calculate minimum CPU intervals
int leastInterval(vector<char>& tasks, int n) {

    int freq[26] = {0};

    // Count frequency of each task
    for (char t : tasks) {
        freq[t - 'A']++;
    }

    // Find maximum frequency
    int maxFreq = *max_element(freq, freq + 26);

    // Count tasks having maximum frequency
    int countMaxFreq = 0;

    for (int f : freq) {
        if (f == maxFreq)
            countMaxFreq++;
    }

    // Apply greedy formula
    int intervals = (maxFreq - 1) * (n + 1)
                    + countMaxFreq;

    return max((int)tasks.size(), intervals);
}

int main() {

    int m, n;

    cout << "Enter number of tasks: ";
    cin >> m;

    if (m < 0) {
        cout << "Invalid input";
        return 0;
    }

    vector<char> tasks(m);

    cout << "Enter task labels: ";

    for (int i = 0; i < m; i++) {
        cin >> tasks[i];

        if (tasks[i] < 'A' || tasks[i] > 'Z') {
            cout << "Invalid task label";
            return 0;
        }
    }

    cout << "Enter cooldown period: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid cooldown period";
        return 0;
    }

    cout << "Minimum CPU intervals: "
         << leastInterval(tasks, n) << endl;

    return 0;
}
