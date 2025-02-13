#include <bits/stdc++.h>
using namespace std;

int main()
{
    int temp;
    cout << "Enter temperature in centigrade: ";
    cin >> temp;

    if (temp < 0)
    {
        cout << "Freezing weather" << endl;
    }
    else if (temp >= 0 && temp <= 10)
    {
        cout << "Very Cold weather" << endl;
    }
    else if (temp > 10 && temp <= 20)
    {
        cout << "Cold weather" << endl;
    }
    else if (temp > 20 && temp <= 30)
    {
        cout << "Normal in Temp" << endl;
    }
    else if (temp > 30 && temp < 40)
    {
        cout << "Its Hot" << endl;
    }
    else
    {
        cout << "Its Very Hot" << endl;
    }

    return 0;
}