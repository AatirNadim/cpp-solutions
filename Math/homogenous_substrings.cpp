// problem link --> https://leetcode.com/problems/count-number-of-homogenous-substrings/

// my solution link --> https://leetcode.com/problems/count-number-of-homogenous-substrings/discuss/3127600/C%2B%2B-oror-Math-oror-Short-and-Simple

class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size(), idx = 0;
        int res = 0, temp = 0, val = 1e9 + 7;
        while(idx < n) {
            res = (res%val + (++temp)%val)%val;
            char c = s[idx++];
            while(idx < n and s[idx] == c) {
                res = (res%val + (++temp)%val)%val;
                idx++;
            }
            temp = 0;
        }
        return res;
    }
};