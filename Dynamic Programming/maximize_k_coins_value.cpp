// problem link --> https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

// my solution link --> https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/discuss/3419367/C%2B%2B-oror-Table-DP-oror-O(m*n*k)-time-oror-O(m*k)-space-oror-Intuitive


class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int m = piles.size(), total_coins_yet = 0;
        vector<vector<int>> dp(m, vector<int>(k+1));
        dp[0][1] = piles[0][0];
        for(int j=2;j<=min((int)piles[0].size(), k); j++)
            dp[0][j] = dp[0][j-1] + piles[0][j-1];
        for(int l=1;l<=k;l++) {
//             for every iteration
            total_coins_yet = piles[0].size();
            for(int i=1;i<m;i++) {
                if(total_coins_yet >= l) dp[i][l] = dp[i-1][l];
                int n = piles[i].size(), currsum = 0;
                for(int j=0;j<min(n, l);j++) {
                    int rem_wanted = l - j - 1;
                    currsum += piles[i][j];
//                     before this iteration
                    if(total_coins_yet >= rem_wanted)
                        dp[i][l] = max(dp[i][l], currsum + dp[i-1][rem_wanted]);
                }
                total_coins_yet += n;
            }
        }
        return dp[m-1][k];
    }
};