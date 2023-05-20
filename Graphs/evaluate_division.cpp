// problem link --> https://leetcode.com/problems/evaluate-division/

// my solution link --> https://leetcode.com/problems/evaluate-division/discuss/3544485/C%2B%2B-oror-Graph-oror-Short-and-Simple


class Solution {
public:
    double val = 0.0;
    unordered_map<string, unordered_map<string, double>> adj;
    unordered_map<string, bool> vis;
    void dfs(string currnode, string end, unordered_map<string, bool>& vis, double curr) {
        if(val) return;
        if(currnode == end) {
            val = curr; return;
        }
        vis[currnode] = 1;
        for(auto& child : adj[currnode]) {
            if(vis[child.first]) continue;
            dfs(child.first, end, vis, curr*child.second);
        }
        vis[currnode] = 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        for(int i=0;i<n;i++) {
            adj[equations[i][0]][equations[i][1]] = values[i];
            adj[equations[i][1]][equations[i][0]] = 1/values[i];
        }
        vector<double> res;    
        for(vector<string>& query: queries) {
            val = 0.0;
            
            if(adj.count(query[0]) and adj.count(query[1])) {
                dfs(query[0], query[1], vis, 1.0);
                if(val) res.push_back(val);
                else res.push_back(-1);
            }
            else res.push_back(-1);
        }
        return res;
    }
};