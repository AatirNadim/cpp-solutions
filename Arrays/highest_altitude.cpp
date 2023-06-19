// problem link --> https://leetcode.com/problems/find-the-highest-altitude/

// my solution link --> https://leetcode.com/problems/find-the-highest-altitude/discuss/3656111/C%2B%2B-oror-0ms-oror-Short-and-Simple

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int val = 0, res = 0;
        for(int& i : gain) {
            val += i;
            res = max(res, val);
        }
        return res;
    }
};