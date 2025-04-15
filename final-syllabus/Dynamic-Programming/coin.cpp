#include <bits/stdc++.h>
using namespace std;

// Problem 1: Minimum number of coins
int minCoins(int total, vector<int> &coins)
{
    vector<int> dp(total + 1, INT_MAX);
    dp[0] = 0;

    for (int amt = 1; amt <= total; amt++)
    {
        for (int coin : coins)
        {
            if (amt >= coin && dp[amt - coin] != INT_MAX)
            {
                dp[amt] = min(dp[amt], dp[amt - coin] + 1);
            }
        }
    }

    return dp[total] == INT_MAX ? -1 : dp[total];
}

// Problem 2: Maximum number of ways to make the total
int countWays(int total, vector<int> &coins)
{
    vector<int> dp(total + 1, 0);
    dp[0] = 1;

    for (int coin : coins)
    {
        for (int amt = coin; amt <= total; amt++)
        {
            dp[amt] += dp[amt - coin];
        }
    }

    return dp[total];
}

int main()
{
    int n, total;
    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter total amount: ";
    cin >> total;

    int minCoinCount = minCoins(total, coins);
    int totalWays = countWays(total, coins);

    if (minCoinCount == -1)
        cout << "It is not possible to make the total with given coins.\n";
    else
        cout << "Minimum number of coins: " << minCoinCount << endl;

    cout << "Total number of ways to make the amount: " << totalWays << endl;

    return 0;
}