// problem link --> https://leetcode.com/problems/domino-and-tromino-tiling/

// my solution link --> https://leetcode.com/problems/domino-and-tromino-tiling/discuss/2946821/C%2B%2B-oror-100-faster-oror-O(n2)-to-O(n)-step-by-step


// O(n^2) solution
#define ll long long int
class Solution {
public:
    int numTilings(int n) {
        vector<ll> dp(n+1);
        int val = 1e9 + 7;
        if(n < 3) return n;
        dp[0] = 1; dp[1] = 1, dp[2] = 2, dp[3] = 5;
        for(int i=4;i<=n;i++) {
            dp[i] = (dp[i-1]%val + dp[i-2]%val)%val;
            for(int j=3;j<=i;j++) {
                dp[i] += (dp[i-j]%val + dp[i-j]%val)%val;
            }
        }
        return (int)(dp[n]%val);
    }
};

// O(n) solution

#define ll long long int
class Solution {
public:
    int numTilings(int n) {
        vector<ll> dp(n+1);
        int val = 1e9 + 7;
        if(n < 3) return n;
        vector<ll> sum_dp(n+1);
        dp[0] = 1; dp[1] = 1, dp[2] = 2, dp[3] = 5;
        sum_dp[0] = 1, sum_dp[1] = 2, sum_dp[2] = 4, sum_dp[3] = 9;
        for(int i=4;i<=n;i++) {
            dp[i] = (dp[i-1]%val + dp[i-2]%val)%val;
            
            int val1 = (sum_dp[i-3]%val + sum_dp[i-3]%val)%val;
            
            dp[i] = (dp[i]%val + val1%val)%val;
            
            sum_dp[i] = (sum_dp[i-1]%val + dp[i]%val)%val;
        }
        return (int)(dp[n]%val);
    }
};

// O(n) time O(1) space

#define ll long long int
class Solution {
public:
    int numTilings(int n) {
        vector<ll> dp(4);
        int val = 1e9 + 7;
        if(n < 3) return n;
        vector<ll> sum_dp(4);
        dp[0] = 1; dp[1] = 1, dp[2] = 2, dp[3] = 5;
        sum_dp[0] = 1, sum_dp[1] = 2, sum_dp[2] = 4, sum_dp[3] = 9;
        for(int i=4;i<=n;i++) {
            dp[i%4] = (dp[(i-1)%4]%val + dp[(i-2)%4]%val)%val;
            
            int val1 = (sum_dp[(i-3)%4]%val + sum_dp[(i-3)%4]%val)%val;
            
            dp[i%4] = (dp[i%4]%val + val1%val)%val;
            
            sum_dp[i%4] = (sum_dp[(i-1)%4]%val + dp[i%4]%val)%val;
        }
        return (int)(dp[n%4]%val);
    }
};