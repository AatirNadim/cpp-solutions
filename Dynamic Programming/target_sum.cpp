/*
    problem link --> https://leetcode.com/problems/target-sum/
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0), limit = 2*sum;
        if(target > sum or target < -sum) return 0;
        vector<vector<int>> dp(n, vector<int>(limit+1));
        dp[0][nums[0] + sum] = 1;
        dp[0][sum - nums[0]] += 1;
        for(int i=1;i<n;i++) {
            for(int j=-sum;j<=sum;j++) {
                if(j-nums[i]+sum > -1)
                    dp[i][j+sum] += dp[i-1][j-nums[i]+sum];
                if(j+nums[i]+sum <= limit)
                    dp[i][j+sum] += dp[i-1][j+nums[i]+sum];
            }
        }
        return dp[n-1][target+sum];
    }
};