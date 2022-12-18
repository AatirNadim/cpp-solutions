// problem link --> https://leetcode.com/problems/daily-temperatures/

// my solution link --> https://leetcode.com/problems/daily-temperatures/discuss/2926431/C%2B%2B-oror-Stack-oror-Easy

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(st.size() and temperatures[st.top()] <= temperatures[i]) st.pop();
            if(st.size()) res[i] = st.top() - i;
            else res[i] = 0;
            st.push(i);
        }
        return res;
    }
};