// problem link --> https://leetcode.com/problems/longest-subsequence-with-limited-sum/

// my solution link --> https://leetcode.com/problems/longest-subsequence-with-limited-sum/discuss/2950453/C%2B%2B-oror-O(nlogn)-time-complexity-oror-95-faster

class Solution {
public:
    int func(vector<int>& nums, int currval, int n) {
        int minval = 0, maxval = n-1, medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(nums[medval] == currval) return medval + 1;
            if(nums[medval] < currval) minval = medval + 1;
            else maxval = medval - 1;
        }
        return maxval + 1;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1;i<n;i++) nums[i] += nums[i-1];
        vector<int> res;
        for(int i : queries) {
            res.push_back(func(nums, i, n));
        }
        return res;
    }
};