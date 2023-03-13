// problem link --> https://leetcode.com/problems/possible-bipartition/

// my solution link --> https://leetcode.com/problems/possible-bipartition/discuss/2934959/C%2B%2B-oror-DFS-%2B-Hashing-oror-Short-and-Intuitive

class Solution {
public:
    bool res = 1;
    void dfs(vector<vector<int>>& adj, int currnode, int be_part, vector<int>& hash) {
        if(!res) return;
        if(hash[currnode]) {
            if(hash[currnode] - be_part) res = 0;
            return;
        }
        hash[currnode] = be_part;
        for(int& child : adj[currnode]) {
            dfs(adj, child, -be_part, hash);
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(vector<int>& edge : dislikes) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> hash(n+1, 0);
        for(int i=1;i<=n;i++) {
            if(!res or hash[i]) continue;
            dfs(adj, i, 1, hash);
        }
        return res;
    }
};