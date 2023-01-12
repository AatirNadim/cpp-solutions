// problem link --> https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/


// my solution link --> https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/discuss/3039711/C%2B%2B-oror-DFS-oror-Simple-Approach

class Solution {
public:
    vector<int> res;
    vector<bool> vis;
    bool isLeaf(vector<vector<int>>& adj, int currnode) {
        return adj[currnode].size() == 1 and vis[adj[currnode][0]];
    }
    void sum_up(vector<int>& ret_hash, vector<int>& temp) {
        for(int i=0;i<26;i++) ret_hash[i] += temp[i];
    }
    vector<int> dfs(vector<vector<int>>& adj, int currnode, string &labels) {
        vector<int> ret_hash(26);
        if(isLeaf(adj, currnode)) {
            res[currnode] = 1;
            ret_hash[labels[currnode] - 'a'] = 1;
            return ret_hash;
        }
        vis[currnode] = 1;
        for(int& child : adj[currnode]) {
            if(vis[child]) continue;
            vector<int> temp = dfs(adj, child, labels);
            sum_up(ret_hash, temp);
        }
        ret_hash[labels[currnode] - 'a']++;
        res[currnode] = ret_hash[labels[currnode] - 'a'];
        return ret_hash;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        res = vector<int> (n);
        vis = vector<bool> (n);
        for(vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> char_hash(26);
        dfs(adj, 0, labels);
        return res;
    }
};