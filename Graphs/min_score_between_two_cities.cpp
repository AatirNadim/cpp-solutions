// problem link --> https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

// my solution link --> https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/discuss/3328267/C%2B%2B-oror-BFS-oror-Short-and-Simple

typedef pair<int, int> pi;
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> hash(n+1, INT_MAX);
        vector<vector<pi>> adj(n + 1);
        for(vector<int>& road : roads) {
            adj[road[0]].push_back({road[2],road[1]});
            adj[road[1]].push_back({road[2],road[0]});
        }
        queue<pi> q;
        for(pi& childNode : adj[1]) {
            hash[childNode.second] = childNode.first;
            q.push(childNode);
        }
        while(q.size()) {
            pi currnode = q.front(); q.pop();
            for(pi& childNode : adj[currnode.second]) {
                int min_from_curr = min(hash[currnode.second], childNode.first);
                if(hash[childNode.second] > min_from_curr) {
                    hash[childNode.second] = min_from_curr;
                    q.push(childNode);
                }
            }
        }
        return hash[n];
    }
};