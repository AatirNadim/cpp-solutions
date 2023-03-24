// problem link --> https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

// my solution link --> https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/discuss/3335431/C%2B%2B-oror-DFS-oror-Intuitive-Approach-oror-With-Comments


class Solution {
public:
    int res = 0;
    vector<vector<int>> adj;
    vector<bool> vis;
    unordered_map<int, unordered_map<int, bool>> leading;
    void dfs(int root) {
        vis[root] = 1;
        for(int& child : adj[root]) {
            if(vis[child]) continue;
//             for all the child nodes not leading to the parent node, (and thus ultimately to 0, incerment the result by 1)
            res += leading[root].count(child);
            dfs(child);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        adj = vector<vector<int>> (n);
//         first make the tree bidirectional to reach all nodes from node 0.
        for(vector<int>& con : connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
            leading[con[0]][con[1]] = 1;
        }
        vis = vector<bool> (n);
//         spread out the traversal from root or node 0.
        dfs(0);
        return res;
    }
};