#include <bits/stdc++.h>
using namespace std;

struct Item {
    float weight;
    float profit;
    float ratio;
};

void knapsack(int n, vector<Item>& items, float capacity) {
    float tp = 0;
    vector<float> x(n, 0.0);

    for (int i = 0; i < n; i++) {
        if (items[i].weight > capacity) {
            x[i] = capacity / items[i].weight;
            tp = tp + (x[i] * items[i].profit);
            break;
        } else {
            x[i] = 1.0;
            tp = tp + items[i].profit;
            capacity = capacity - items[i].weight;
        }
    }

    cout << "\nThe result vector is:- ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
    }
    cout << "\nMaximum profit is: " << tp << endl;
}

int main() {
    int num;
    float capacity;

    cout << "\nEnter the number of objects: ";
    cin >> num;

    vector<Item> items(num);

    cout << "\nEnter the weights and profits of each object:\n";
    for (int i = 0; i < num; i++) {
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = items[i].profit / items[i].weight;
    }

    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    cout << "\nEnter the capacity of the knapsack: ";
    cin >> capacity;

    knapsack(num, items, capacity);

    return 0;
}