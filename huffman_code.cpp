// Huffman Code Implementation with TC O(NlogN) by Het B. Patel :)

#include <bits/stdc++.h>
using namespace std;

vector<pair<char,string>> create_huffman(string s){
    for(int i=0 ; i<s.size() ; i++) s[i]=tolower(s[i]);

    unordered_map<char,int> freq;
    for(int i=0 ; i<s.size() ; i++){
        freq[s[i]]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> node;
    for(auto it : freq){
        node.push({it.second, int(it.first)});
    }

    int x=200;
    vector<int> adj[1000];
    while(node.size()!=1){
        x++;
        pair<int,int> n1=node.top();
        node.pop();
        pair<int,int> n2=node.top();
        node.pop();
        // cout<<char(n1.second)<<" "<<char(n2.second)<<" "<<n1.first<<" "<<n2.first<<" "<<char(x)<<"\n";
        node.push({n1.first+n2.first, x});
        adj[x].push_back(n1.second);
        adj[x].push_back(n2.second);
    }

    unordered_map<int,string> code;

    queue<int> q;
    unordered_map<int,int> vis;
    q.push(x);
    while(!q.empty()){
        int y=q.front();
        q.pop();
        for(auto it : adj[y]){
            code[it]+=code[y];
            if(!vis[y]) code[it].push_back('0');
            else code[it].push_back('1');
            vis[y]++;
            // cout<<char(it)<<" ";
            q.push(it);
        }
    }

    vector<pair<char, string>> huff_code;
    for(auto it : freq){
        huff_code.push_back({it.first, code[int(it.first)]});
    }

    return huff_code;
}

int main()
{
    string s;
    cout<<"Enter Data Input string : ";
    getline(cin, s);
    vector<pair<char,string>> code=create_huffman(s);
    cout<<"\nHuffman Codes for the Given string are :\n\n";
    cout<<"Character\tHuffman Code\n";
    for(int i=0 ; i<code.size() ; i++){
        cout<<code[i].first<<"\t\t"<<code[i].second<<"\n";
    }
    return 0;
}