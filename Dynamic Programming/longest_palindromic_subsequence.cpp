// problem link --> https://leetcode.com/problems/longest-palindromic-subsequence/

// my solution link --> https://leetcode.com/problems/longest-palindromic-subsequence/discuss/3415721/C%2B%2B-oror-DP-oror-O(n2)-time-oror-O(n)-space-oror-Short-and-Simple

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n));
        for(int i=n-1;i>=0;i--) {
            for(int j=i;j<n;j++) {
                if(i==j) {
                    dp[i&1][j] = 1; continue;
                }
                if(s[i] == s[j]) dp[i&1][j] = dp[(i+1)&1][j-1] + 2;
                dp[i&1][j] = max({dp[i&1][j], dp[(i+1)&1][j], dp[i&1][j-1]});
            }
        }
        return dp[0][n-1];
    }
};