// problem link --> https://leetcode.com/problems/number-of-provinces/

// my solution link --> https://leetcode.com/problems/number-of-provinces/discuss/3001574/C%2B%2B-oror-Graph-oror-DFS-oror-Easy

class Solution {
public:
    void dfs(vector<vector<int>>& adj, int currnode, vector<bool>& vis) {
        vis[currnode] = 1;
        for(int& child : adj[currnode]) {
            if(vis[child]) continue;
            vis[child] = 1;
            dfs(adj, child, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n);
        for(int i=0;i<n;i++) {
            if(vis[i]) continue;
            res++;
            dfs(adj, i, vis);
        }
        return res;
    }
};