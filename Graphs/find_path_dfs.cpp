// problem link --> https://leetcode.com/problems/find-if-path-exists-in-graph/

// my solution link --> https://leetcode.com/problems/find-if-path-exists-in-graph/discuss/2929158/C%2B%2B-oror-DFS-oror-Short-and-Simple

class Solution {
public:
    bool res = 0;
    void dfs(vector<vector<int>>& adj, int currnode, int dest, vector<bool>& vis) {
        if(res) return;
        if(currnode == dest) {
            res = 1; return;
        }
        vis[currnode] = 1;
        for(int& child : adj[currnode]) {
            if(vis[child]) continue;
            dfs(adj, child, dest, vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n);
        vis[source] = 1;
        dfs(adj, source, destination, vis);
        return res;
    }
};