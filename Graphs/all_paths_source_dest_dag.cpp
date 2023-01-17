// problem link --> https://leetcode.com/problems/all-paths-from-source-to-target/

// my solution link --> https://leetcode.com/problems/all-paths-from-source-to-target/discuss/2970262/C%2B%2B-oror-DFS-oror-Short-and-Simple


class Solution {
public:
    vector<vector<int>> res; int n;
    void dfs(vector<vector<int>>& graph, int currnode, vector<int>& temp) {
        if(currnode == n-1) {
            res.push_back(temp); return;
        }        
        for(int& child : graph[currnode]) {
            temp.push_back(child);
            dfs(graph, child, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> temp = {0};
        dfs(graph, 0, temp);
        return res;
    }
};