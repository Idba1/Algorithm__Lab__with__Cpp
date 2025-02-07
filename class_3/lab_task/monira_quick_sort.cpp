#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &m, int l, int r)
{
    int pivot = m[l];
    int i = l;
    int j = r;

    while (i < j)
    {
        while (m[i] <= pivot)
        {
            i++;
        }
        while (m[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(m[i], m[j]);
        }
    }
    swap(m[l], m[j]);
    return j;
}

void monira_islam(vector<int> &m, int l, int r)
{
    if (l < r)
    {
        int k = partition(m, l, r);
        monira_islam(m, l, k - 1);
        monira_islam(m, k + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> m;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        m.push_back(element);
    }

    cout << "given array -> ";
    for (int i = 0; i < n; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;

    cout << "sorted array -> ";
    monira_islam(m, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;

    return 0;
}