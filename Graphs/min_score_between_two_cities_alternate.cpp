// problem link --> https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

// my solution link --> https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/discuss/3328323/C%2B%2B-oror-Graph-oror-BFS-oror-Alternate-Approach

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, bool> mp;
        vector<vector<int>> adj(n + 1);
        for(vector<int>& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        queue<int> q;
        int res = INT_MAX;
        q.push(1);
        while(q.size()) {
            int currnode = q.front(); q.pop();
            mp[currnode] = 1;
            for(int& child : adj[currnode]) {
                if(mp.count(child)) continue;
                q.push(child);
            }
        }
        for(vector<int>& road : roads) {
            if(mp[road[0]] and mp[road[1]]) 
                res = min(res, road[2]);
        }
        return res;
    }
};