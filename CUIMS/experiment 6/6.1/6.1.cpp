#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {

    if (s.length() != t.length())
        return false;

    unordered_map<char, char> sToT, tToS;

    for (int i = 0; i < s.length(); i++) {

        char cs = s[i];
        char ct = t[i];

        // Check mapping from s to t
        if (sToT.count(cs) && sToT[cs] != ct)
            return false;

        // Check mapping from t to s
        if (tToS.count(ct) && tToS[ct] != cs)
            return false;

        // Store mappings
        sToT[cs] = ct;
        tToS[ct] = cs;
    }

    return true;
}

int main() {
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isIsomorphic(s, t))
        cout << "Strings are Isomorphic";
    else
        cout << "Strings are Not Isomorphic";

    return 0;
}
