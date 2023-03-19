// problem link --> https://leetcode.com/problems/design-add-and-search-words-data-structure/

// my solution link --> https://leetcode.com/problems/design-add-and-search-words-data-structure/discuss/3314962/C%2B%2B-oror-Trie-oror-Insert-and-Search

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> edges;
    TrieNode() {
        isEnd = 0;
        edges = vector<TrieNode*>(26);
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* curr = root;
        for(char &c : word) {
            if(!curr->edges[c - 'a']) curr->edges[c - 'a'] = new TrieNode();
            curr = curr->edges[c - 'a'];
        }
        curr->isEnd = 1;
    }
    bool search(TrieNode* curr, string word, int idx) {
        if(idx == word.size()) return curr->isEnd;
        if(word[idx] - '.') {
            return curr->edges[word[idx] - 'a'] and search(curr->edges[word[idx] - 'a'], word, idx + 1);
        }
        for(int i=0;i<26;i++) {
            if(curr->edges[i] and search(curr->edges[i], word, idx + 1)) return 1;
        }
        return 0;
    }
    bool search(string word) {
        return search(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */