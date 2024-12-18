/*
    problem link --> https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

    my solution link --> https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/discuss/6158606/C%2B%2B-oror-0ms-oror-Stack-oror-Simple-and-Efficient

*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> res(n);
        for(int i=n - 1;i>=0;i--) {
            while(st.size() and st.top() > prices[i]) st.pop();
            res[i] = prices[i] - (st.size() ? st.top() : 0);
            st.push(prices[i]);
        }
        return res;
    }
};