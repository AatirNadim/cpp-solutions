// basic trie implementaion with structure


#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
    bool isEnd;
    vector<TrieNode*> edges;
    TrieNode() {
        isEnd = 0;
        edges = vector<TrieNode*> (26); //handled for all lowercase characters or all uppercase characters at a time
    }  //or any set of characters represented sequentially, with the total number of such characters being 26
};      //here, taking all lowercase letters
void insert(TrieNode* root, string s) {
    TrieNode* curr = root;
    for(char c : s) {
        if(!curr->edges[c - 'a']) curr->edges[c - 'a'] = new TrieNode();
        curr = curr->edges[c - 'a'];
    }
    curr->isEnd = 1;
}
bool isPresent(TrieNode* root, string s) {
    TrieNode* curr = root;
    for(char c : s) {
        if(!curr->edges[c - 'a']) return 0;
        curr = curr->edges[c - 'a'];
    }
    return curr->isEnd;
}
void deleteEntry(TrieNode* root, string s) {
    TrieNode* curr = root;
    for(char c : s) curr = curr->edges[c - 'a'];
    curr->isEnd = 0; //string to be deleted might be a part of a bigger string
    // this is not the most efficient method to delete an entry from the trie but works fine without much memory constraint
}
int main() {
    TrieNode* root = new TrieNode();
    cout<<"Give the total number of strings to enter into the trie"<<endl;
    int n;cin>>n;
    cout<<"Give the strings to enter into the trie"<<endl;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(string s : v) insert(root, s);
    cout<<"Give string to search in the trie"<<endl;
    string temp;cin>>temp;
    (isPresent(root, temp))? cout<<"String present in the trie":cout<<"string not present in the trie";
    cout<<"\nGive string to delete"<<endl;
    cin>>temp;
    if(isPresent(root, temp)) {
        deleteEntry(root, temp);
        cout<<"String successfully deleted"<<endl;   
    }
    else {
        cout<<"String not present in the trie"<<endl;
    }
    return 0;
    
}