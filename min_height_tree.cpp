// problem link --> https://leetcode.com/problems/minimum-height-trees/


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> leaves;
        vector<unordered_set<int>> adj(n);
        for(vector<int>& v: edges) {
            adj[v[0]].insert(v[1]);
            adj[v[1]].insert(v[0]);
        }
        for(int i=0;i<n;i++) {
            if(adj[i].size() == 1) leaves.push_back(i);
        }
        for(int i: leaves) cout<<i<<" ";
        int remaining = n;
        while(remaining > 2) {
            remaining -= leaves.size();
            vector<int> newLeaves;
            for(int leaf: leaves) {
                int parent = *(adj[leaf].begin());
                adj[leaf].erase(parent);
                adj[parent].erase(leaf);
                if(adj[parent].size() == 1) newLeaves.push_back(parent);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};