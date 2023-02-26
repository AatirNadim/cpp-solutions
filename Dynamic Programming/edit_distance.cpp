// problem link --> https://leetcode.com/problems/edit-distance/

// my solution link --> https://leetcode.com/problems/edit-distance/discuss/3232061/C%2B%2B-oror-Bottom-Up-oror-Table-DP-oror-Short-and-Simple

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(!m or !n) return m + n;
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i and j) {
                    if(word1[i] == word2[j]) dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
                }
                else if(i) {
                    if(word1[i] == word2[j]) dp[i][j] = max(dp[i-1][j], i);
                    else dp[i][j] = 1 + dp[i-1][j];
                }
                else if(j) {
                    if(word1[i] == word2[j]) dp[i][j] = max(dp[i][j-1], j);
                    else dp[i][j] = 1 + dp[i][j-1];
                }
                else dp[0][0] = (word1[0] != word2[0]);
            }
        }
        return dp[m-1][n-1];
    }
};