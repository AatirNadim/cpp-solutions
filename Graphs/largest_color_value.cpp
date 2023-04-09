// problem link --> https://leetcode.com/problems/largest-color-value-in-a-directed-graph/

// my solution link --> https://leetcode.com/problems/largest-color-value-in-a-directed-graph/discuss/3397588/C%2B%2B-oror-DFS-oror-HashTable-oror-Short-and-Simple


class Solution {
public:
    unordered_map<int, vector<int>> hash;
    int res = 0;
    void dfs(vector<vector<int>>& adj, int& currnode, string& colors, int& pass, vector<bool>& done) {
        if(res == -1) return;
        if(hash[currnode].size()) {
            if(done[currnode]) {
                res = -1;
            }
            return;
        }
        done[currnode] = 1;
        hash[currnode] = vector<int>(26);
        for(int& child: adj[currnode]) {
            dfs(adj, child, colors, pass, done);
            if(res == -1) return;
            for(int i=0;i<26;i++)
                hash[currnode][i] = max(hash[currnode][i], hash[child][i]);
        }
        hash[currnode][colors[currnode] - 'a']++;
        res = max(res, hash[currnode][colors[currnode] - 'a']);
        done[currnode] = 0;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), pass = 0;
        vector<bool> done(n);
        vector<vector<int>> adj(n);
        for(vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<n;i++) {
            if(res == -1) break;
            dfs(adj, i, colors, pass, done);
            pass++;
        }
        return res;
    }
};