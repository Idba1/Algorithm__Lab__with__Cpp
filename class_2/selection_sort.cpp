#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int temp = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
    }
}

int main()
{
    int n, element;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> element;
        v.push_back(element);
    }

    selection_sort(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
