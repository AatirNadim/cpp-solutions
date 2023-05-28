// problem link --> https://leetcode.com/problems/stone-game/

// my solution link --> https://leetcode.com/problems/stone-game/discuss/3573050/C%2B%2B-oror-The-Long-way-oror-O(n2)-time-oror-O(n)-space

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(2, vector<int>(n));
        for(int i=n-1;i>=0;i--) {
            for(int j=i;j<n;j++) {
                if(i - j) {
                    dp[i&1][j] = max(piles[i] - dp[(i+1)&1][j], piles[j] - dp[i&1][j-1]);
                }
                else dp[i&1][j] = piles[i];
            }
        }
        return dp[0][n-1] > 0;
    }
};