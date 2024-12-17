/*
    problem link --> https://www.geeksforgeeks.org/problems/hamiltonian-path2522/1
*/

class Solution
{
    
    bool allVisited(vector<bool>& vis) {
        for(int i = 1;i<vis.size();i++) {
            if(!vis[i]) return 0;
        }
        return 1;
    }
    
    void func(vector<vector<int>>& adj, vector<bool>& vis, int currnode) {
        if(res or vis[currnode]) return;
        vis[currnode] = 1;
        bool nextPath = 0;
        bool rootAsChild = 0;
        for(int child: adj[currnode]) {
            // rootAsChild = rootAsChild or (child == 1);
            if(vis[child]) continue;
            nextPath = 1;
            func(adj, vis, child);
        }
        if(!nextPath and allVisited(vis)) res = 1;
        vis[currnode] = 0;
    }
    
    public:
    
    bool res = 0;
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        
        vector<bool> vis(N + 1);
        vector<vector<int>> adj(N + 1);
        for(vector<int>& edge: Edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=1;i<=N and !res;i++) {
            func(adj, vis, i);
            
        }
        return res;
    }
};