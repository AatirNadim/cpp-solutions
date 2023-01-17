// problem link --> https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// my solution link --> https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/discuss/3001303/C%2B%2B-oror-Greedy-oror-Sorting

class Solution {
public:
    static bool compt(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), idx = 1;
        sort(points.begin(), points.end(), compt);
        int curr = points[0][1], res = 0;
        while(idx < n) {
            if(points[idx][0] > curr) {
                res++; curr = points[idx][1];
            }
            idx++;
        }
        return res + 1;
    }
};