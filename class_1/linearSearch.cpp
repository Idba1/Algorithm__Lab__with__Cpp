#include <bits/stdc++.h>
using namespace std;

int LinearSearch(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> v;
    int sz, element, target;

    cout << "enter the number of elements: ";
    cin >> sz;

    cout << "enter the elements: ";
    for (int i = 0; i < sz; i++)
    {
        cin >> element;
        v.push_back(element);
    }

    cout << "enter target for Linear Search: ";
    cin >> target;

    int linearResult = LinearSearch(v, target);

    if (linearResult != -1)
    {
        cout << "Element found at index " << linearResult << endl;
    }
    else
    {
        cout << "element not found" << endl;
    }

    return 0;
}