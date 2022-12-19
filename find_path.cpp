// problem link --> https://leetcode.com/problems/find-if-path-exists-in-graph/

// my solution link --> https://leetcode.com/problems/find-if-path-exists-in-graph/discuss/2929140/C%2B%2B-oror-BFS-oror-93-faster-oror-74-less-memory

class Solution {
public:
    bool func(int n, vector<vector<int>>& adj, int source, int dest) {
        vector<bool> vis(n);
        vis[source] = 1;
        queue<int> q;
        q.push(source);
        while(q.size()) {
            int currnode = q.front(); q.pop();
            if(currnode == dest) return 1;
            for(int& child : adj[currnode]) {
                if(vis[child]) continue;
                vis[child] = 1;
                q.push(child);
            }
        }
        return 0;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return func(n, adj, source, destination);
    }
};