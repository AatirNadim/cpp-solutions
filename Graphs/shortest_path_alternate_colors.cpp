// problem link --> https://leetcode.com/problems/shortest-path-with-alternating-colors/

// my solution link --> https://leetcode.com/problems/shortest-path-with-alternating-colors/discuss/3173078/C%2B%2B-oror-BFS-oror-Hash-Table-oror-Short-and-Simple


typedef pair<int, int> pi;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pi>> adj(n);
        for(vector<int>& edge : redEdges) {
            adj[edge[0]].push_back({edge[1], 0});
        }
        for(vector<int>& edge : blueEdges) {
            adj[edge[0]].push_back({edge[1], 1});
        }
        vector<int> res(n, INT_MAX);
        vector<vector<bool>>vis(n, vector<bool>(2)) ;
        res[0] = 0;
        queue<pair<pi, int>> q;
        for(pi& child: adj[0]) {
            if(vis[child.first][child.second]) continue;
            res[child.first] = min(res[child.first], 1);
            vis[child.first][child.second] = 1;
            q.push({child, 1});
        }
        while(q.size()) {
            pi currnode = q.front().first; int dist = q.front().second; q.pop();
            for(pi& child : adj[currnode.first]) {
                if(child.second == currnode.second) continue;
                if(vis[child.first][child.second]) continue;
                res[child.first] = min(res[child.first], dist + 1);
                vis[child.first][child.second] = 1;
                q.push({child, dist + 1});
            }
        }
        for(int& i : res) {
            if(i == INT_MAX) i =-1;
        }
        return res;
        
    }
};