#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int r)
{
    int pivot = v[l];
    int i = l;
    int j = r;

    while (i < j)
    {
        while (v[i] <= pivot)
        {
            i++;
        }
        while (v[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(v[i], v[j]);
        }
    }
    swap(v[l], v[j]);
    return j;
}

void quick_sort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int k = partition(v, l, r);
        quick_sort(v, l, k - 1);
        quick_sort(v, k + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }

    cout << "given array -> ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "sorted array -> ";
    quick_sort(v, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}