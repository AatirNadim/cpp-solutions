// problem link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// my solution link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/3227807/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minval = prices[0], res = 0;
        for(int& i : prices) {
            minval = min(minval, i);
            res = max(res, i - minval);
        }
        return res;
    }
};