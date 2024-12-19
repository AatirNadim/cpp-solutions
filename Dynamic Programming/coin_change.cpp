/*
    problem link --> https://www.geeksforgeeks.org/problems/coin-change2448/1
*/

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=sum;j++) {
                dp[i][j] += dp[i - 1][j];
                if(j >= coins[i - 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[n][sum];
        
    }
};