// problem link --> https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

// my solution link --> https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/discuss/3338492/C%2B%2B-oror-Graph-oror-DFS-oror-95-faster-oror-Explaination


#define ll long long int
class Solution {
public:
    ll res = 0, currnodes = 0;
    vector<bool> vis;
    void dfs(vector<vector<int>>& adj, int currnode) {
        vis[currnode] = 1;
        currnodes++;
//         to traverse across the component
        for(int& child : adj[currnode]) {
            if(vis[child]) continue;
            dfs(adj, child);
        }
    }
    ll countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vis = vector<bool> (n);
        vector<ll> hash;
        ll curr_sum = 0;
//         for the adjacency list
        for(vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++) {
            if(vis[i]) continue;
//             to determine the different components and the number of nodes per component
            currnodes = 0;
            dfs(adj, i);
            hash.push_back(currnodes);
            curr_sum += currnodes;
        }
//         to calculate the number of pairs across the components
        for(ll& val : hash) {
//             to calculate remaining nodes which would form pairs
            curr_sum -= val;
            res += val*curr_sum;
        }
        return res;
    }
};