/*
    problem link --> https://leetcode.com/problems/two-best-non-overlapping-events/
    solution link --> https://leetcode.com/problems/two-best-non-overlapping-events/discuss/6125245/C%2B%2B-oror-Sort-%2B-Binary-Search-oror-Most-Efficient-Approach
*/

class Solution {
    
    int getMaxPossible(vector<vector<int>>& events, vector<int>& maxYet, int curr) {
        int res = 0;
        int minval = curr + 1, maxval = events.size() - 1, medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(events[medval][0] <= events[curr][1]) minval = medval + 1;
            else maxval = medval - 1;
        }
        return minval >= events.size() ? 0 : maxYet[minval];
    }
    
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int n = events.size(), res = 0;
        vector<int> maxYet(n);
        maxYet[n - 1] = events[n - 1][2];
        for(int i=n - 2;i>=0;i--) {
            maxYet[i] = max(maxYet[i + 1], events[i][2]);
        }
        for(int i=0;i<n;i++) {
            res = max(res, events[i][2] + getMaxPossible(events, maxYet, i));
        }
        return res;
    }
};

