// Question link --> 
// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/
// My solution link on leetcode
// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/solutions/2710801/c-91-faster-75-less-memory-straightforward/
// do check it out

#define ll long long int
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<ll>> dp(d+1, vector<ll>(n));
        int val = 0; dp[1][0] = jobDifficulty[0];
        for(int i=1;i<n;i++) {
            dp[1][i] = max(dp[1][i-1], (ll)jobDifficulty[i]);

        }
        for(int i=2;i<=d;i++) {
            for(int j=0;j<n;j++) {
                ll maxval = jobDifficulty[j], res = INT_MAX;
                for(int k=j-1;k>=0;k--) {
                    res = min(res, maxval + dp[i-1][k]);
                    maxval = max(maxval, (ll)jobDifficulty[k]);
                }
                dp[i][j] = res;
            }
        }
        return (dp[d][n-1] == INT_MAX)?-1:(int)dp[d][n-1];
    }
};