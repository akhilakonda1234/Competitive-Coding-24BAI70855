#include <iostream>
using namespace std;

bool divisorGame(int n) {

    if (n == 1) {
        return false;
    }

    for (int x = 1; x < n; x++) {

        if (n % x == 0) {

            if (divisorGame(n - x) == false) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (divisorGame(n)) {
        cout << "Alice wins: true";
    } else {
        cout << "Alice wins: false";
    }

    return 0;
}
