// problem link --> https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

// my solution link --> https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/discuss/3424555/C%2B%2B-oror-Table-DP-oror-Hash-Table-oror-Short-and-Simple

#define ll long long int
class Solution {
public:
    int mod = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        int m = words.size(), n = words[0].size(), k = target.size();
        ll currsum = 0;
        if(n < k) return 0;
        vector<vector<ll>> hash(n, vector<ll>(26));
        vector<vector<ll>> dp(k, vector<ll>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) hash[j][words[i][j] - 'a']++;
        }
        for(int j=0;j<n;j++) {
            currsum += hash[j][target[0] - 'a'];
            dp[0][j] = currsum;
        }
        
        for(int i=1;i<k;i++) {
            for(int j=i;j<n;j++) {
                ll val = (hash[j][target[i] - 'a']%mod * dp[i-1][j-1]%mod)%mod;
                dp[i][j] = (dp[i][j]%mod + val%mod)%mod;
                dp[i][j] = (dp[i][j]%mod + dp[i][j-1]%mod)%mod;
            }
        }
        return (int)dp[k-1][n-1];
    }
};