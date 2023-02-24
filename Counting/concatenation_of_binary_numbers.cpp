// problem link --> https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

// my solution link --> https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/discuss/3224637/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    int val = 1e9 + 7, to_add = 1;
    int func(int n) {
        string s = ""; int res = 0;
        while(n) {
            res = (res%val + ((n&1)*to_add)%val)%val;
            to_add = (to_add%val*2)%val;
            n>>=1;
        }
        return res;
    }
    int concatenatedBinary(int n) {
        int res = 0;
        for(int i=n;i>=1;i--) {
            res = (res%val + func(i)%val)%val;
        }
        return res;
    }
};