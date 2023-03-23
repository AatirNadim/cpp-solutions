// problem link --> https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// my solution link --> https://leetcode.com/problems/number-of-operations-to-make-network-connected/discuss/3333378/C%2B%2B-oror-DFS-oror-Intuitive-Approach-oror-With-Comments



class Solution {
public:
    int no_components = 0, curr_edges = 0, surplus = 0, no_nodes = 0;
    vector<bool> vis;
    void dfs(vector<vector<int>>& adj, int currnode) {
//         same node is not visited again.
        vis[currnode] = 1;
        no_nodes++;
//         ultimtately, this will be halved to find out the no_edges in the component.
        curr_edges += adj[currnode].size();
        for(int& child : adj[currnode]) {
            if(vis[child]) continue;
            dfs(adj, child);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vis = vector<bool> (n);
        for(vector<int>&con : connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
//         determine the no of components
        for(int i=0;i<n;i++) {
            if(vis[i]) continue;
//             find the no_edges and no_components for every component
            curr_edges = 0, no_nodes = 0;
            no_components++;
            dfs(adj, i);
//             add all the extra edges for final condition check
            surplus += (curr_edges>>1) - (no_nodes - 1);
        }
//         (no_components - 1) edges are requires minimum to connect the components
//         if the etxra edges are at least that number, return the answer else return -1.
        return (surplus >= no_components - 1) ? no_components - 1 : -1;
    }
};