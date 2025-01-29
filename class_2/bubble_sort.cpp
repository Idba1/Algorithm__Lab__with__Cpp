#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &v, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
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

    bubble_sort(v, n);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
