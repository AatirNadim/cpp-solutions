// problem link --> https://leetcode.com/problems/detonate-the-maximum-bombs/

// my solution link --> https://leetcode.com/problems/detonate-the-maximum-bombs/discuss/3004015/C%2B%2B-oror-DFS-oror-Simple

typedef pair<int, int> cord;
class Solution {
public:
    int temp = 0;
    map<cord, int> number;
    map<cord, vector<cord>> adj;
    double getDist(cord& c1, cord& c2) {
        double one = c1.second - c2.second, two = c2.first - c1.first;
        return sqrt(one*one + two*two);
    }
    void dfs(cord& currnode, map<cord, bool>& vis) {
        if(vis[currnode]) return;
        vis[currnode] = 1;
        temp += number[currnode];
        for(cord& child : adj[currnode]) {
            if(vis[child]) continue;
            dfs(child, vis);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), res = 0;
        for(vector<int>& bomb : bombs) {
            number[{bomb[0], bomb[1]}]++;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                cord c1 = {bombs[i][0], bombs[i][1]};
                cord c2 = {bombs[j][0], bombs[j][1]};
                double dist = getDist(c1, c2);
                if(bombs[i][2] >= dist)
                    adj[c1].push_back(c2);
                if(bombs[j][2] >= dist)
                    adj[c2].push_back(c1);
            }
        }
        for(vector<int>& bomb : bombs) {
            cord currnode = {bomb[0], bomb[1]};
            map<cord, bool> vis;
            temp = 0;
            dfs(currnode, vis);
            res = max(res, temp);
        }
        return res;
    }
};