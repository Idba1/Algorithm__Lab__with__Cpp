#include <bits/stdc++.h>
using namespace std;

int BinarySearchRecursive(const vector<int> &arr, int left, int right, int target)
{
    if (left > right)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }

    if (arr[mid] > target)
    {
        return BinarySearchRecursive(arr, left, mid - 1, target);
    }

    return BinarySearchRecursive(arr, mid + 1, right, target);
}

int main()
{
    vector<int> v;
    int sz, element, target;

    cout << "enter arr size: ";
    cin >> sz;

    cout << "enter elements -> ";
    for (int i = 0; i < sz; i++)
    {
        cin >> element;
        v.push_back(element);
    }

    sort(v.begin(), v.end());

    cout << "enter target for binary search: ";
    cin >> target;

    int binaryResult = BinarySearchRecursive(v, 0, v.size() - 1, target);

    if (binaryResult != -1)
    {
        cout << "element found at index " << binaryResult << endl;
    }
    else
    {
        cout << "element not found" << endl;
    }

    return 0;
}