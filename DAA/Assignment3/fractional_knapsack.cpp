#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    for (const auto& item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50; // Maximum capacity of knapsack
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

    double maxValue = fractionalKnapsack(capacity, items);
    cout<<"\nMaximum value in knapsack = " << maxValue << endl;

    return 0;
}

// Time Complexity: 𝑂(𝑛log𝑛)
// Space Complexity: 𝑂(𝑛)