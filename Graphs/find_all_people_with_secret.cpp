// problem link --> https://leetcode.com/problems/find-all-people-with-secret/

// my solution link --> https://leetcode.com/problems/find-all-people-with-secret/discuss/2929422/C%2B%2B-oror-Sorting-%2B-BFS-oror-Intuitive-Approach


class Solution {
public:
    vector<int> res; vector<bool> vis;
    static bool compt(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    void func(int n, vector<vector<int>>& temp) {
        unordered_map<int, vector<int>> adj;
        for(vector<int>& edge : temp) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for(auto &p : adj) {
            if(vis[p.first]) {
                q.push(p.first);
            }
        }
        while(q.size()) {
            int curr = q.front(); q.pop();
            for(int& child : adj[curr]) {
                if(vis[child]) continue;
                vis[child] = 1;
                q.push(child);
            }
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), compt);
        vector<vector<int>> temp;
        vis = vector<bool> (n); vis[0] = 1, vis[firstPerson] = 1;
        int left = 0, right = 0, m = meetings.size();
        while(right < m) {
            if(meetings[left][2] - meetings[right][2]) {
                func(n, temp);
                temp.clear(); left = right;
            }
            temp.push_back(meetings[right]);
            right++;
        }
        func(n, temp);
        for(int i=0;i<n;i++) {
            if(vis[i]) res.push_back(i);
        }
        return res;
    }
};