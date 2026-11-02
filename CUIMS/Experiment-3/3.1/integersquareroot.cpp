
#include <iostream>
using namespace std;

int mySqrt(int x) {

    if (x == 0 || x == 1)
        return x;

    long long low = 1, high = x;
    long long ans = 0;

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        if (mid * mid == x) {
            return (int)mid;
        }

        else if (mid * mid < x) {
            ans = mid;
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return (int)ans;
}

int main() {

    int x;

    cout << "Enter a non-negative integer: ";
    cin >> x;

    if (x < 0) {
        cout << "Invalid input";
        return 0;
    }

    cout << "Integer Square Root: " << mySqrt(x);

    return 0;
}
