// problem link --> https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

// my solution link --> https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/discuss/3610243/C%2B%2B-oror-0ms-oror-100-faster-oror-Bit-Manipulation-oror-Short-and-Simple

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int i = 32, res = 0;
        while(i--) {
            if(c&1) {
                res += !((a&1) | (b&1));
            }
            else {
                res += ((a&1) + (b&1));              
            }
            a>>=1, b>>=1, c>>=1;
        }
        return res;
    }
};