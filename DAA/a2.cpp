#include<bits/stdc++.h>
using namespace std;

struct Compare{
    bool operator()(pair<int,int>a, pair<int,int>b){
        return a.second>b.second;
    }
};

void solve(unordered_map<int,pair<int,int>>&tree, int node, string str, vector<string>&code){
    if(tree.find(node)==tree.end()){
        code[node]=str;
        return;
    }
    solve(tree,tree[node].first,str+'0',code);
    solve(tree,tree[node].second,str+'1',code);
}

void huffmanCodes(vector<int>&freq, int n,vector<string>&code){
    unordered_map<int,pair<int,int>>tree;
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pq;

    for(int i=0;i<n;i++) {
        pq.push({i,freq[i]});
    }

    int index=n;
    while(pq.size()>1){
        auto left = pq.top(); pq.pop();
        auto right = pq.top(); pq.pop();

        tree[index] = {left.first,right.first};
        pq.push({index++,left.second+right.second});
    }

    solve(tree,pq.top().first,"",code);
}

int main(){
    string str="abcdef";
    vector<int>freq={5,9,12,13,16,45};

    int n=str.size();
    vector<string>code(n);
    huffmanCodes(freq,n,code);

    cout<<"Huffman Codes:\n";
    for(int i=0;i<n;i++){
        cout<<str[i]<<" : "<<code[i]<<endl;
    }

    return 0;
}