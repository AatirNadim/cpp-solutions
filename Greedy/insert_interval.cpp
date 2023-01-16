// problem link --> https://leetcode.com/problems/insert-interval/

// my solution link --> https://leetcode.com/problems/insert-interval/discuss/3058433/C%2B%2B-oror-90-faster-oror-Short-and-Simple

// alternative solution link --> https://leetcode.com/problems/insert-interval/discuss/3058589/C%2B%2B-oror-Greedy-oror-Single-Traversal-oror-Alternative-Approach

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res, res1;
        int n = intervals.size(), idx = 0;
        while(idx < n and intervals[idx][0] < newInterval[0]) 
            res.push_back(intervals[idx++]);
        res.push_back(newInterval);
        while(idx < n) res.push_back(intervals[idx++]);
        int left = res[0][0], right = res[0][1]; idx = 1;
        while(idx < n+1) {
            if(right < res[idx][0]) {
                res1.push_back({left, right});
                left = res[idx][0], right = res[idx][1];
            }
            else right = max(right, res[idx][1]);
            idx++;
        }
        res1.push_back({left, right});
        return res1;
    }
};


// alternative solution 

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int idx = 0, n = intervals.size();
        if(!n) return {newInterval};
        while(idx < n and intervals[idx][1] < newInterval[0])
            res.push_back(intervals[idx++]);
        if(idx == n) {
            res.push_back(newInterval);
            return res;
        }
        int left = min(intervals[idx][0], newInterval[0]), right;
        if(newInterval[1] < intervals[idx][0]) {
            right = newInterval[1];
        }
        else {
            right = max(newInterval[1], intervals[idx][1]); idx++;
        }
        while(idx < n) {
            if(right < intervals[idx][0]) {
                res.push_back({left, right});
                left = intervals[idx][0], right = intervals[idx][1];
            }
            else right = max(right, intervals[idx][1]);
            idx++;
        }
        res.push_back({left, right});
        return res;
    }
};