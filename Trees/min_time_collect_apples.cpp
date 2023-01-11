// problem link --> https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

// my solution link --> https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/discuss/3037269/C%2B%2B-oror-Special-DFS-oror-Intuitive

class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    bool isLeaf(int currnode) {
        return adj[currnode].size() == 1 and vis[adj[currnode][0]];
    }
    int dfs(int currnode, int time_spent_yet, vector<bool>& hasApple) {
        if(isLeaf(currnode)) {
            if(hasApple[currnode]) return time_spent_yet + 1;
            return 0;
        }
        vis[currnode] = 1;
        vector<int> children;
        int left_time = 0, right_time = 0;
        for(int& child : adj[currnode]) {
            if(vis[child]) continue;
            children.push_back(child);
        }
        int m = children.size(), temp = 0;
        for(int i=0;i<m;i++) {
            int val = (temp) ? temp : time_spent_yet;
            
            int curr_temp = dfs(children[i], val + 1, hasApple);
            if(curr_temp) temp = curr_temp;
        }
        if(temp) return temp + 1;
        if(hasApple[currnode]) return time_spent_yet + 1;
        return 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj = vector<vector<int>>(n);
        vis = vector<bool> (n);
        for(vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return max(dfs(0, 0, hasApple) - 1, 0) ;
        
    }
};