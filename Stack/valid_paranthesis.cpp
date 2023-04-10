// problem link --> https://leetcode.com/problems/valid-parentheses/

// my solution link --> https://leetcode.com/problems/valid-parentheses/discuss/3399962/C%2B%2B-oror-Stack-oror-O(n)-time-oror-O(n)-space

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, int> mp;
        mp['('] = 1, mp[')'] = -1, mp['{'] = 2, mp['}'] = -2, mp['['] = 3, mp[']'] = -3;
        for(char& c: s) {
            if(mp[c] < 0) {
                if(!st.size() or st.top() + mp[c]) return 0;
                st.pop();
            }
            else st.push(mp[c]);
        }
        return !st.size();
    }
};