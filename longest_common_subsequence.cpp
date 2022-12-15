// problem link --> https://leetcode.com/problems/longest-common-subsequence/

// my solution link --> https://leetcode.com/problems/longest-common-subsequence/discuss/2913987/C%2B%2B-oror-DP-oror-Tabular-oror-Easy

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = text1[0] == text2[0];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i and j) {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    if(text1[i] == text2[j]) dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
                }
                else if(i) {
                    dp[i][j] = max(dp[i-1][j], (int)(text1[i] == text2[0]));
                }
                else if(j) {
                    dp[i][j] = max(dp[i][j-1], (int)(text2[j] == text1[0]));
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};