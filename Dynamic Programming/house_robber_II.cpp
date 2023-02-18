// problem link --> https://leetcode.com/problems/house-robber-ii/

// my solution link --> https://leetcode.com/problems/house-robber-ii/discuss/3202793/C%2B%2B-oror-DP-oror-Short-and-Simple

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return *max_element(nums.begin(), nums.end());
        int res = 0;
        vector<int> dp(n);
        dp[0] = nums[0], dp[1] = nums[1];
        for(int i=2;i<n-1;i++) {
            dp[i] = nums[i] + max(dp[i-2], (i > 2) ? dp[i-3] : 0);
            res = max(res, dp[i]);
        }
        dp = vector<int>(n);
        dp[0] = nums[0], dp[1] = nums[1], dp[2] = nums[2];
        for(int i=3;i<n;i++) {
            dp[i] = nums[i] + max(dp[i-2], (i > 3) ? dp[i-3] : 0);
            res = max(res, dp[i]);
        }
        return res;
    }
};