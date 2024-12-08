/*
    problem link --> https://www.geeksforgeeks.org/problems/number-of-coins1824/1
*/

class Solution {

  public:
    int minCoins(vector<int> &coins, int sum) {
        // Your code goes here
        int n = coins.size();
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=sum;i++) {
            for(int j=0;j<n;j++) {
                dp[i] = min(dp[i], (i >= coins[j] and dp[i - coins[j]] != INT_MAX) ? 
                dp[i - coins[j]] + 1: INT_MAX);
            }
        }
        return dp[sum] == INT_MAX ? -1: dp[sum];
    }
};