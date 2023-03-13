// problem link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// my solution link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/2943018/C%2B%2B-oror-92-faster-oror-O(n2)-to-O(n)-step-by-step-oror-Intuitive


// O(n^2) solution 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0;
        vector<int> dp(n);
        for(int i=1;i<n;i++) {
            dp[i] = max(dp[i], prices[i] - prices[0]);
            int maxval = 0;
            for(int j=1;j<i;j++) {
                int val = prices[j];
                if(j > 1) maxval = max(maxval, dp[j-2]);
                val -= maxval;
                dp[i] = max(dp[i], prices[i]- val);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


// O(n) solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        if(n == 1) return 0;
        vector<int> max_res(n), to_subtract_min_yet(n);
        max_res[1]= max(0, prices[1] - prices[0]);
        to_subtract_min_yet[0] = prices[0];
        to_subtract_min_yet[1] = min(prices[1], prices[0]);
        for(int i=2;i<n;i++) {
            max_res[i] = max(max_res[i-1], prices[i] - to_subtract_min_yet[i-1]);
            to_subtract_min_yet[i] = min(to_subtract_min_yet[i-1], prices[i] - max_res[i-2]);
        }
        return max_res[n-1];
    }
};