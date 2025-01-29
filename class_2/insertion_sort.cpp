#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(v[i], v[min]);
        }
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

    insertion_sort(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
