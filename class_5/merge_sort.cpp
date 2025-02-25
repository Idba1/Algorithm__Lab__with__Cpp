#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int p, int q, int r)
{
    vector<int> b(r - p + 1);
    int i = p, j = q + 1, k = 0;
    while (i <= q && j <= r)
    {
        if (v[i] < v[j])
        {
            b[k++] = v[i++];
        }
        else
        {
            b[k++] = v[j++];
        }
    }
    while (i <= q)
    {
        b[k++] = v[i++];
    }
    while (j <= r)
    {
        b[k++] = v[j++];
    }
    for (i = r; i >= p; i--)
    {
        v[i] = b[--k];
    }
}

void mergeSort(vector<int> &v, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(v, p, q);
        mergeSort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

void printArray(vector<int> &v)
{
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> v(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    printArray(v);
    mergeSort(v, 0, n - 1);
    printArray(v);

    return 0;
}