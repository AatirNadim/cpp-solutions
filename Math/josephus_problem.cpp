// problem link --> https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
//     func(n, k) = (func(n-1, k) + k - 1)%n + 1
    int findTheWinner(int n, int k) {
        vector<int> dp(2);
        dp[1] = 1;
        for(int i=2;i<=n;i++) {
            dp[i&1] = (dp[(i-1)&1] + k - 1)%i + 1;
        }
        return dp[n&1];
    }
};