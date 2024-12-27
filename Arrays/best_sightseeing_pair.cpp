/*
    problem link --> https://leetcode.com/classic/problems/best-sightseeing-pair/
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxval, res = INT_MIN;
        int n = values.size();
        maxval = values[0];
        for(int i=1;i<n;i++) {
            res = max(res, maxval + values[i] - i);
            maxval = max(maxval, values[i] + i);
        }
        return res;
    }
};