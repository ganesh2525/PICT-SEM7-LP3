#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

struct Node {
    int level;
    int profit;
    int weight;
    double bound;
};

bool cmp(const Item& a, const Item& b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double calculateBound(Node u, int n, int w, vector<Item>& items) {
    if (u.weight >= w)
        return 0;

    double bound = u.profit;
    int j = u.level + 1;
    int totWeight = u.weight;

    while ((j < n) && (totWeight + items[j].weight <= w)) {
        totWeight += items[j].weight;
        bound += items[j].value;
        j++;
    }

    if (j < n)
        bound += (w - totWeight) * (double)items[j].value / items[j].weight;

    return bound;
}

int knapSack(int w, vector<int>& wt, vector<int>& val,int n) {
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i] = {wt[i], val[i]};
    }

    sort(items.begin(), items.end(), cmp);

    queue<Node>q;
    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    q.push(u);

    int maxProfit = 0;

    while (!q.empty()) {
        u = q.front();
        q.pop();

        if (u.level == -1)
            v.level = 0;
        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;

        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;

        if (v.weight <= w && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = calculateBound(v, n, w, items);

        if (v.bound > maxProfit)
            q.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = calculateBound(v, n, w, items);

        if (v.bound > maxProfit)
            q.push(v);
    }

    return maxProfit;
}

int main() {
    int n=3,w=50;
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    cout << "Maximum profit (Branch and Bound) = " << knapSack(w,wt,val,n) << endl;
    return 0;
}

// Time: O(2^n), in worst case the algorithm may explore all possible subsets of items.
// Space: O(n), due to the storage of item details 