#include <bits/stdc++.h>
using namespace std;

int countWays(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int a = 1, b = 1, result;
    for (int i = 2; i <= n; i++)
    {
        result = a + b;
        b = a;
        a = result;
    }
    return result;
}

int main()
{
    int steps = 10;
    cout << "Total ways to reach step " << steps << ": " << countWays(steps) << endl;
    return 0;
}