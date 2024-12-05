/*
    problem link --> https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
*/


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	stack<int> st;
	
	void func(int currnode, vector<vector<int>>& adj, vector<bool>& vis, bool update) {
	    vis[currnode] = 1;
	    for(int& child: adj[currnode]) {
	        if(vis[child]) continue;
	        func(child, adj, vis, update);
	    }
	    if(update) st.push(currnode);
	}
	
	
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool> vis(V);
        int res = 0;
        for(int i=0;i<V;i++) {
            if(vis[i]) continue;
            func(i, adj, vis, 1);
        }
        vector<vector<int>> adjT(V);
        for(int i=0;i<V;i++) {
            for(int& child: adj[i]) {
                adjT[child].push_back(i);
            }
        }
        vis = vector<bool>(V);
        while(st.size()) {
            int currnode = st.top(); st.pop();
            if(vis[currnode]) continue;
            res++;
            func(currnode, adjT, vis, 0);
        }
        return res;
        
    }
};