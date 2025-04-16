#include <bits/stdc++.h>
using namespace std;

pair<int, string> LCS(string X, string Y)
{
    int m = X.length(), n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // dp
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // track back
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return {dp[m][n], lcs};
}

int main()
{
    string firstName = "Monira";
    string lastName = "Islam";

    auto result = LCS(firstName, lastName);

    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "LCS Length: " << result.first << endl;
    cout << "LCS: " << result.second << endl;

    return 0;
}