// problem link --> https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

// my solution link --> https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/discuss/3176626/C%2B%2B-oror-DFS-oror-85-faster-oror-Easy-Understanding

#define ll long long
typedef pair<int, int> pi;
class Solution {
public:
    ll res = 0;
    vector<bool> vis;
//     total cars filled, total strength in the last car
    bool isLeaf(vector<vector<int>>& adj, int root) {
        return adj[root].size() == 1 and vis[adj[root][0]];
    }
    pi dfs(vector<vector<int>>& adj, int root, int parent, int& maxSeats) {
        if(isLeaf(adj, root)) {
            res++;
            if(maxSeats == 1) return {1, 0};
            return {0, 1};
        }
        int total_filled = 0, strength = 0;
        vis[root] = 1;
        for(int &child : adj[root]) {
            if(child == parent) continue;
            pi temp = dfs(adj, child, root, maxSeats);
            total_filled += temp.first, strength += temp.second;
        }
        if(!root) return {0, 0};
//         current person
        strength++;
        int val1 = total_filled + strength/maxSeats;
        int val2 = (strength%maxSeats != 0);
        res += val1 + val2;
        return {val1, strength%maxSeats};
    }
    ll minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for(vector<int>& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        vis = vector<bool> (n);
        dfs(adj, 0, -1, seats);
        return res;
   }
};