// problem link --> https://leetcode.com/problems/insert-interval/

// my solution link --> https://leetcode.com/problems/insert-interval/discuss/3058433/C%2B%2B-oror-90-faster-oror-Short-and-Simple


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