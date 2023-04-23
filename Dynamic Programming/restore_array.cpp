// problem link --> https://leetcode.com/problems/restore-the-array/

// my solution link --> https://leetcode.com/problems/restore-the-array/discuss/3446823/C%2B%2B-oror-Table-DP-oror-97-less-memory-oror-O(n)-time

#define ll long long int
class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfArrays(string s, int k) {
        int n = s.size(), idx = 0, idx1;
        ll val = 0,  temp = 1;
        vector<int> dp(11);
        while(idx < n) {
            if(idx and !dp[(idx - 1 + 11)%11]) {
                dp[idx%11] = 0; 
                idx++;
                continue;
            }
            dp[idx%11] = 0;
            idx1 = idx - 1;  temp = 1; val = s[idx] - '0';
            while(idx1 > -1 and val <= (ll)k and temp <= INT_MAX) {
                if(s[idx1 + 1] - '0') {
                    dp[idx%11] = (dp[idx%11]%mod + dp[idx1%11]%mod)%mod;
                }
                temp*= 10;
                val += temp*(s[idx1] - '0');
                idx1--;
            }
            if(val <= k and temp <= INT_MAX) {
                dp[idx%11] = (dp[idx%11]%mod + 1)%mod;
            }
            idx++;
        }
        return dp[(n-1)%11];
    }
};