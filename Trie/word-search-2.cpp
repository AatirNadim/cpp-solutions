// Word search 2, leetcode.
struct TrieNode {
    bool isEnd;
    vector<TrieNode*> edges;
    TrieNode() {
        times = 0; isEnd = 0;
        edges = vector<TrieNode*> (26, nullptr);
    }
};
class Solution {
public:
    TrieNode* root;
    int m, n, k;
    unordered_map<string, bool> mp;
    void insert(string s) {
        TrieNode* currnode = root;
        for(char c : s) {
            if(!currnode->edges[c - 'a']) currnode->edges[c - 'a'] = new TrieNode();
            currnode = currnode->edges[c -'a'];
        }
        currnode->isEnd = 1;
    }
    void func(TrieNode* currnode, vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j, string& temp) {
        if(mp.size() == k) return;
        if(currnode->isEnd) mp[temp] = 1;
        if(i < 0 or i == m or j < 0 or j == n) return;
        if(vis[i][j]) return;
        if(currnode->edges[board[i][j] - 'a']) {
            vis[i][j] = 1; temp.push_back(board[i][j]);
            func(currnode->edges[board[i][j] - 'a'], board, vis, i+1, j, temp);
            func(currnode->edges[board[i][j] - 'a'], board, vis, i-1, j, temp);
            func(currnode->edges[board[i][j] - 'a'], board, vis, i, j+1, temp);
            func(currnode->edges[board[i][j] - 'a'], board, vis, i, j-1, temp);
            vis[i][j] = 0, temp.pop_back();
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        m = board.size(), n = board[0].size(), k = words.size(); string temp = "";
        vector<vector<bool>> vis(m, vector<bool>(n));
        vector<string> res;
        for(string s : words) {
            insert(s);
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(root->edges[board[i][j] - 'a']) 
                func(root, board, vis, i, j, temp);
            }
        }
        for(auto &p: mp) res.push_back(p.first);
        return res;
    }
};