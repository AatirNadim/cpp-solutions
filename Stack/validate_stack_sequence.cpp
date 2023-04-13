// problem link --> https://leetcode.com/problems/validate-stack-sequences/

// my solution link --> https://leetcode.com/problems/validate-stack-sequences/discuss/3413224/C%2B%2B-oror-Stack-oror-Two-Pointers-oror-Short-and-Simple

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int left = 0, right = 0, n = pushed.size();
        while(left < n and right < n) {
            if(st.size() and st.top() == popped[right]) {
                st.pop(); right++;
            }
            else st.push(pushed[left++]);
        }
        while(right < n) {
            if(popped[right] - st.top()) return 0;
            st.pop(); right++;
        }
        return 1;
    }
};