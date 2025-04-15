#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value, weight;

    Item(int v, int w)
    {
        value = v;
        weight = w;
    }
};

// Compare function for sorting items by value/weight ratio
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (int i = 0; i < items.size(); i++)
    {
        if (W == 0)
            break;

        if (items[i].weight <= W)
        {
            W -= items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            double fraction = (double)W / items[i].weight;
            totalValue += items[i].value * fraction;
            W = 0;
        }
    }

    return totalValue;
}

int main()
{
    int n, maxWeight;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        int value, weight;
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    cout << "Enter maximum weight of knapsack: ";
    cin >> maxWeight;

    double maxVal = fractionalKnapsack(maxWeight, items);
    cout << "Maximum value in knapsack = " << maxVal << endl;

    return 0;
}