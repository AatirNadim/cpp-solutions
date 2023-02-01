// problem link --> https://leetcode.com/problems/number-of-substrings-with-only-1s/

// my solution link --> https://leetcode.com/problems/number-of-substrings-with-only-1s/discuss/3127513/C%2B%2B-oror-Short-and-Simple

#define ll long long int
class Solution {
public:
    int numSub(string s) {
        int val = 1e9 + 7;
        int n = s.size(), idx = 0;
        int res = 0, temp = 0;
        while(idx < n and s[idx] == '0') idx++;
        while(idx < n) {
            while(idx < n and s[idx] == '1') {
                res = (res%val + (++temp)%val)%val;
                idx++;
            }
            temp = 0;
            while(idx < n and s[idx] == '0') idx++;
        }
        return (int)res%val;
    }
};