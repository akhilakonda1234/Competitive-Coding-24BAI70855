#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChangeBruteForce(vector<int>& coins, int amount) {
    if (amount == 0)
        return 0;

    int ans = amount + 1;

    for (int coin : coins) {
        if (coin <= amount) {
            int result = coinChangeBruteForce(coins, amount - coin);

            if (result != amount + 1)
                ans = min(ans, result + 1);
        }
    }

    return ans;
}

int main() {
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    int result = coinChangeBruteForce(coins, amount);

    if (result == amount + 1)
        cout << "Minimum coins = -1" << endl;
    else
        cout << "Minimum coins = " << result << endl;

    return 0;
}
