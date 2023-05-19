// problem link --> https://leetcode.com/problems/is-graph-bipartite/

// my solution link --> https://leetcode.com/problems/is-graph-bipartite/discuss/3542253/C%2B%2B-oror-DFS-oror-Short-and-Simple

class Solution {
public:
    bool res = 1;
    void dfs(vector<vector<int>>& graph, int& currnode, vector<int>& vis, int flag) {
        if(!res) return;
        vis[currnode] = flag;
        for(int& child : graph[currnode]) {
            if(vis[child]) {
                if(vis[child] == flag) {
                    res = 0; return;
                }
            }
            else dfs(graph, child, vis, -flag);
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n);
        for(int i=0;i<n;i++) {
            if(!res) break;
            if(vis[i]) continue;
            dfs(graph, i, vis , 1);
        }
        return res;
    }
};