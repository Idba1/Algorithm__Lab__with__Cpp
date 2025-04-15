#include <bits/stdc++.h>
using namespace std;

long long factorial(int n)
{
    vector<long long> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] * i;
    }

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter n for Factorial: ";
    cin >> n;

    cout << n << "! = " << factorial(n) << endl;
    return 0;
}