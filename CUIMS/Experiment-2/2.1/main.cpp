
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int i = s.length() - 1;
    int len = 0;

    while (i >= 0 && s[i] == ' ')
        i--;

    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }

    cout << "Length of last word: " << len << endl;

    return 0;
}
