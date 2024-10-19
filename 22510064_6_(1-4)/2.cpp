#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight, profit;
};

bool compareByProfit(Item a, Item b) {
    return a.profit > b.profit;
}

bool compareByWeight(Item a, Item b) {
    return a.weight < b.weight;
}

bool compareByRatio(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int capacity, vector<Item>& items, bool (*compare)(Item, Item)) {
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;

    for (int i = 0; i < items.size(); i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            totalProfit += (double)items[i].profit * ((double)capacity / items[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].profit;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Largest-Profit Strategy: " << fractionalKnapsack(capacity, items, compareByProfit) << endl;
    cout << "Smallest-Weight Strategy: " << fractionalKnapsack(capacity, items, compareByWeight) << endl;
    cout << "Largest Profit-Weight Ratio Strategy: " << fractionalKnapsack(capacity, items, compareByRatio) << endl;

    return 0;
}
