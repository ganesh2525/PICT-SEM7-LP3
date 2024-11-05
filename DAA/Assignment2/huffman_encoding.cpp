#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(pair<int,int>a, pair<int,int>b) {
        return a.second > b.second;
    }
};

void solve(unordered_map<int, pair<int,int>>&tree, int node, string str, vector<string>&code) {
    if (tree.find(node) == tree.end()) {
        code[node] = str;
        return;
    }
    solve(tree, tree[node].first, str + '0', code);
    solve(tree, tree[node].second, str + '1', code);
}

void huffmanCodes(vector<int>&freq, int n, vector<string>&code) {
    unordered_map<int, pair<int,int>> tree;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    for (int i=0; i<n; i++) {
        pq.push({i, freq[i]});
    }

    int index = n;
    while (pq.size() > 1) {
        auto left = pq.top(); pq.pop();
        auto right = pq.top(); pq.pop();

        tree[index] = {left.first, right.first};
        pq.push({index++, left.second + right.second});
    }
    
    solve(tree, pq.top().first,"",code);
}

int main() {
    string str = "abcdef";
    vector<int>freq = {5, 9, 12, 13, 16, 45}; 

    int n = str.size();
    vector<string>code(n);
    huffmanCodes(freq,n,code);

    cout<<"Huffman Codes:\n";
    for(int i=0; i<n; i++) {
        cout<<str[i]<<" : "<<code[i]<<'\n';
    }

    return 0;
}

/*
Time: 
1) Building the Huffman Tree: O(nlogn), as inserting 𝑛 nodes into a min-heap which takes O(logn) per insertion
2) Generating Codes: O(n), as each character is assigned a code by traversing the tree.

Space: 
1) Space for tree nodes: O(n), since there are n leaf nodes and 𝑛−1 internal nodes in a Huffman tree, 
giving a total of 2𝑛−1 nodes
2) Space for Storing Codes: 𝑂(𝑛), as each character has a corresponding binary code
*/

