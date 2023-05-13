// problem link --> https://leetcode.com/problems/count-ways-to-build-good-strings/

// my solution link --> https://leetcode.com/problems/count-ways-to-build-good-strings/discuss/3518731/C%2B%2B-oror-Table-DP-oror-Short-and-Simple-oror-O(high)-timeorspace

class Solution {
public:
    int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        int res = 0; dp[0] = 1;
        for(int i=1;i<=high;i++) {
            if(i >= zero) dp[i] = (dp[i]%mod + dp[i-zero]%mod)%mod;
            if(i >=one) dp[i] = (dp[i]%mod + dp[i - one]%mod)%mod;
            if(i>= low) res = (res%mod + dp[i]%mod)%mod;
        }
        return res;
    }
};