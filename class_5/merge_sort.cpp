#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int p, int q, int r)
{
    vector<int> b(r - p + 1);
    int i = p, j = q + 1, k = 0;
    while (i <= q && j <= r)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= q)
    {
        b[k++] = a[i++];
    }
    while (j <= r)
    {
        b[k++] = a[j++];
    }
    for (i = r; i >= p; i--)
    {
        a[i] = b[--k];
    }
}

void mergeSort(vector<int> &a, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

void printArray(vector<int> &a)
{
    for (int num : a)
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