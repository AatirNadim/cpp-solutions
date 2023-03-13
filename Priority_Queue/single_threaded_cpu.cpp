// problem link --> https://leetcode.com/problems/single-threaded-cpu/

// my solution link --> https://leetcode.com/problems/single-threaded-cpu/discuss/2966314/C%2B%2B-oror-O(nlogn)-time-oror-O(n)-space

// another implemenation --> https://leetcode.com/submissions/detail/729530054/

#define ll long long int
typedef pair<int, int> pi;
class Solution {
public:
    static bool compt(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        map<pair<int, int>, queue<int>> mp;
        int n= tasks.size();
        for(int i=0;i<n;i++) mp[{tasks[i][0], tasks[i][1]}].push(i);
        sort(tasks.begin(), tasks.end(), compt);
        vector<int> res; int idx = 1; ll curr_time = tasks[0][0];
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int curr_idx = mp[{tasks[0][0], tasks[0][1]}].front();
        mp[{tasks[0][0], tasks[0][1]}].pop();
        pq.push({tasks[0][1], curr_idx});
        while(pq.size()) {
            auto p = pq.top(); pq.pop();
            curr_time += p.first;
            res.push_back(p.second);
            while(idx < n and (ll)tasks[idx][0] <= curr_time) {
                curr_idx = mp[{tasks[idx][0], tasks[idx][1]}].front();
                mp[{tasks[idx][0], tasks[idx][1]}].pop();
                pq.push({tasks[idx][1], curr_idx});
                idx++;   
            }
            if(!pq.size() and idx < n) {
                curr_time = tasks[idx][0];
                curr_idx = mp[{tasks[idx][0], tasks[idx][1]}].front();
                mp[{tasks[idx][0], tasks[idx][1]}].pop();
                pq.push({tasks[idx][1], curr_idx}); 
                idx++;
            }
        }
        return res;
    }
};