// problem link --> https://leetcode.com/problems/implement-trie-prefix-tree/

// my solution link --> https://leetcode.com/problems/implement-trie-prefix-tree/discuss/3306593/C%2B%2B-oror-Trie-oror-Short-and-Simple

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> edges;
    TrieNode() {
        isEnd = 0;
        edges = vector<TrieNode*> (26);
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* currnode = root;
        for(char &c : word) {
            if(!currnode->edges[c - 'a']) currnode->edges[c - 'a'] = new TrieNode();
            currnode = currnode->edges[c - 'a'];
        }
        currnode->isEnd = 1;
    }
    
    TrieNode* traverse(string word) {
        int n = word.size();
        TrieNode* currnode = root;
        for(int i = 0; i < n and currnode; i++) {
            currnode = currnode->edges[word[i] - 'a'];
        }
        return currnode;
    }
    
    bool search(string word) {
        TrieNode* currnode = traverse(word);
        return (currnode and currnode->isEnd);
    }
    
    bool startsWith(string prefix) {
        TrieNode* currnode = traverse(prefix);
        return currnode;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */