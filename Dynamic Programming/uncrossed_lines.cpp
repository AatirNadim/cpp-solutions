// problem link --> https://leetcode.com/problems/uncrossed-lines/

// my solution link --> https://leetcode.com/problems/uncrossed-lines/discuss/3511864/C%2B%2B-oror-LCS-oror-Short-and-Simple

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(2, vector<int>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i and j) {
                    dp[i&1][j] = max({dp[(i-1)&1][j], dp[i&1][j-1], dp[(i-1)&1][j-1] + (nums1[i] == nums2[j])});
                }
                else if(i) {
                    dp[i&1][j] = max(dp[(i-1)&1][0], (int)(nums1[i] == nums2[0]));
                }
                else if(j) {
                    dp[i&1][j] = max(dp[0][j-1], (int)(nums1[0] == nums2[j]));        
                }
                else dp[0][0] = nums1[0] == nums2[0];
            }
        }
        return dp[(m-1)&1][n-1];
    }
};