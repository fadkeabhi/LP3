#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item
{
public:
    int value, weight;
    double ratio;

    Item(int value, int weight) : value(value), weight(weight)
    {
        ratio = (double)value / weight;
    }
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double fractional_knapsack(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end(), compare);

    double total_value = 0.0;
    for (auto &item : items)
    {
        if (capacity >= item.weight)
        {
            capacity -= item.weight;
            total_value += item.value;
        }
        else
        {
            total_value += item.value * ((double)capacity / item.weight);
            break;
        }
    }

    return total_value;
}

int main()
{
    vector<Item> items = {
        Item(60, 10),
        Item(100, 20),
        Item(120, 30)};
    int capacity = 50;
    double max_value = fractional_knapsack(items, capacity);
    cout << "Maximum value in Knapsack = " << max_value << endl;
    return 0;
}