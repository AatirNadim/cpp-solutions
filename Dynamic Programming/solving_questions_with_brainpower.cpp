// problem link --> https://leetcode.com/problems/solving-questions-with-brainpower/

// my solution link --> https://leetcode.com/problems/solving-questions-with-brainpower/discuss/3515617/C%2B%2B-oror-O(n)-time-oror-O(n)-space-oror-DP-oror-Short-and-Simple


#define ll long long int
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n);
        dp[n-1] = questions[n-1][0];
        for(int i=n-2;i>=0;i--) {
            ll val = 0;
            if(i + questions[i][1] + 1 <= n-1) val = dp[i + questions[i][1] + 1];
            dp[i] = max(dp[i+1], val + questions[i][0]);
        }
        return dp[0];
    }
};