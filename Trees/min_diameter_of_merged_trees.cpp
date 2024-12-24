/*
    problem link --> https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/

    my solution link --> https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/discuss/6180267/C%2B%2B-oror-Diameter-oror-Simple-and-Efficient
*/

class Solution {
    
    void getFarthest(vector<vector<int>>& adj, int currnode, int parent, int currHeight, int& maxNode, int& maxHeight) {
        if(maxHeight < currHeight) {
            maxNode = currnode;
            maxHeight = currHeight;
        }
        for(int& child: adj[currnode]) {
            if(child == parent) continue;
            getFarthest(adj, child, currnode, currHeight + 1, maxNode, maxHeight);
        }
    }
    
    int getMinLen(vector<vector<int>>& adj, int n) {
        int maxNode = -1, maxHeight = -1;
        getFarthest(adj, 0, -1, 0, maxNode, maxHeight);
        int leaf1 = maxNode;
        maxNode = -1;
        maxHeight = -1;
        getFarthest(adj, leaf1, -1, 0, maxNode, maxHeight);
        maxres = max(maxres, maxHeight);
        return (maxHeight/2) + (maxHeight&1);
    }
    
public:
    typedef pair<int, bool> pi;
    int maxres = 0;
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int m = edges1.size() + 1, n = edges2.size() + 1;
        vector<vector<int>> adj1(m), adj2(n);
        for(vector<int>& edge: edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(vector<int>& edge: edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        int val1 = getMinLen(adj1, m);
        int val2 = getMinLen(adj2, n);
        // cout<<val1<<" "<<val2<<"\n";
        return max(maxres, val1 + val2 + 1);
    }
};