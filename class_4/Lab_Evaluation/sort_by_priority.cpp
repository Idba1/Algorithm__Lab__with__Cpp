#include <bits/stdc++.h>
using namespace std;

void sort_by_priority(vector<pair<string, int>> &tasks)
{
    int n = tasks.size();
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (tasks[j].second > tasks[maxIndex].second)
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            swap(tasks[i], tasks[maxIndex]);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of tasks: ";
    cin >> n;

    vector<pair<string, int>> tasks;
    string taskName;
    int priority;

    cout << "Enter task name and priority (1-10):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> taskName >> priority;
        tasks.push_back({taskName, priority});
    }

    sort_by_priority(tasks);

    cout << "Tasks sorted by priority:" << endl;
    for (auto task : tasks)
    {
        cout << task.first << " (Priority: " << task.second << ")" << endl;
    }

    return 0;
}