// problem link --> https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

// my solution link --> https://leetcode.com/problems/longest-path-with-different-adjacent-characters/discuss/3044056/C%2B%2B-oror-86-faster-oror-Graph-%2B-DFS-oror-Intuitive

typedef pair<char, int> pi;
class Solution {
public:
    int res = 0;
    bool isLeaf(vector<vector<int>>& adj, int& currnode) {
        return !adj[currnode].size();
    }
    pi dfs(vector<vector<int>>& adj, int currnode, string& s) {
        if(isLeaf(adj, currnode)) {
            res = max(res, 1);
            return {s[currnode], 1};
        }
        pi maxi = {'0', -1}, secmax = {'0', -1};
        for(int& child : adj[currnode]) {
            pi temp = dfs(adj, child, s);
            if(temp.first - s[currnode]) {
                if(maxi.second < temp.second) secmax = maxi, maxi = temp;
                else if(secmax.second < temp.second) secmax = temp;
            }
        }
        if(maxi.second + 1 and secmax.second + 1) {
            res = max(res, maxi.second + secmax.second + 1);
            return {s[currnode], maxi.second + 1};
        }
        if(maxi.second + 1) {
            res = max(res, maxi.second + 1);
            return {s[currnode], maxi.second + 1};   
        }
        return {s[currnode], 1};
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++) adj[parent[i]].push_back(i);
        dfs(adj, 0, s);
        return res;
    }
};