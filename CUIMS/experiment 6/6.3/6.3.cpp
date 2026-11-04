#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool isOneLetterDifferent(string a, string b) {
    int count = 0;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            count++;
        }
    }

    return count == 1;
}

int ladderLength(string beginWord, string endWord,
                 vector<string>& wordList) {

    queue<pair<string, int>> q;
    vector<bool> visited(wordList.size(), false);

    q.push({beginWord, 1});

    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endWord) {
            return steps;
        }

        for (int i = 0; i < wordList.size(); i++) {
            if (!visited[i] &&
                isOneLetterDifferent(word, wordList[i])) {

                visited[i] = true;
                q.push({wordList[i], steps + 1});
            }
        }
    }

    return 0;
}

int main() {
    string beginWord, endWord;
    int n;

    cout << "Enter begin word: ";
    cin >> beginWord;

    cout << "Enter end word: ";
    cin >> endWord;

    cout << "Enter dictionary size: ";
    cin >> n;

    vector<string> wordList(n);

    cout << "Enter dictionary words: ";
    for (int i = 0; i < n; i++) {
        cin >> wordList[i];
    }

    cout << "Shortest transformation length: "
         << ladderLength(beginWord, endWord, wordList);

    return 0;
}
