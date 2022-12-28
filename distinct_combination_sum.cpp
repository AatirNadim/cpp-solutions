
// problem link --> https://leetcode.com/problems/coin-change-ii/

// key excerpt --> if we calculate dp[i] as dp[i] += dp[i - coin] for all coin in coins array, 
// we will mistakenly repeat the frequencies of the coins taken.
// for eg, 4 --> 1, 1, 2 and 1, 2, 1 and 2, 1, 1 should be counted as 1 combination only

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for(int& coin : coins) {
            for(int j=coin;j<=amount;j++)
                dp[j] += dp[j - coin];
        }
        return dp[amount];
    }
};