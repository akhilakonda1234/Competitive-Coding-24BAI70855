#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChangeOptimized(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int a = 1; a <= amount; a++) {
        for (int coin : coins) {
            if (coin <= a) {
                dp[a] = min(dp[a], dp[a - coin] + 1);
            }
        }
    }

    if (dp[amount] <= amount)
        return dp[amount];

    return -1;
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

    int result = coinChangeOptimized(coins, amount);

    cout << "Minimum coins = " << result << endl;

    return 0;
}
