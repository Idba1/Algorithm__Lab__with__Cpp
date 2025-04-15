#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int w, vector<int> &weights, vector<int> &values)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

int main()
{
    int n, maxWeight;
    cout << "Enter number of souvenirs: ";
    cin >> n;
    vector<int> weights(n), values(n);

    cout << "Enter the weights of the souvenirs:\n";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "Enter the emotional values of the souvenirs:\n";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    cout << "Enter maximum suitcase weight: ";
    cin >> maxWeight;

    cout << "Maximum emotional value: " << knapsack(n, maxWeight, weights, values) << endl;

    return 0;
}