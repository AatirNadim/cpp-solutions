// problem link --> https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// my solution link --> https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/discuss/3443415/C%2B%2B-oror-Table-DP-oror-O(n2)-time-oror-O(n)-space-oror-Short-and-Simple

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int> (n));
        for(int i=n-1;i>=0;i--) {
            for(int j=i;j<n;j++) {
                if(i == j){
                    continue;
                }
                dp[i&1][j] = 1 + min(dp[(i+1)&1][j], dp[i&1][j-1]);
                if(s[i] == s[j]) dp[i&1][j] = min(dp[i&1][j], dp[(i+1)&1][j-1]);
            }
        }
        return dp[0][n-1];
    }
};