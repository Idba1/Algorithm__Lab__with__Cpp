#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, vector<int> &weights, vector<int> &values)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, maxWeight;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Enter weights of the items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    cout << "Enter values of the items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    cout << "Enter maximum capacity of knapsack: ";
    cin >> maxWeight;

    int maxValue = knapsack(n, maxWeight, weights, values);
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}