// problem link --> https://leetcode.com/problems/reconstruct-itinerary/

// my solution link --> https://leetcode.com/problems/reconstruct-itinerary/discuss/4045254/C%2B%2B-oror-DFS-oror-Sorted-DFS-oror-Short-and-Simple

class Solution {
public:
    typedef pair<string, int> pi;
    int total_edges; bool done = 0;
    vector<string> global_path;
    void dfs(unordered_map<string, map<string, int>>& adj, string currnode, int covered, vector<string>& local_path) {
        if(done) return;
        if(covered == total_edges) {
            global_path = local_path; done = 1; return;
        }
        for(pi child : adj[currnode]) {
            if(!child.second) continue;
            adj[currnode][child.first]--;
            local_path.push_back(child.first);
            dfs(adj, child.first, covered + 1, local_path);
            local_path.pop_back();
            adj[currnode][child.first]++;
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        total_edges = tickets.size();
        unordered_map<string, map<string, int>> adj;
        for(vector<string>& v : tickets) {
            adj[v[0]][v[1]]++;
        }
        vector<string> local_path = {"JFK"};
        dfs(adj, "JFK", 0, local_path);
        return global_path;
        
    }
};