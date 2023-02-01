// problem link --> https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/

// my solution link --> https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/discuss/3127542/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    int numberOfCuts(int n) {
        if(n < 3) return n-1;
        if(n&1) return n;
        return (n>>1);
    }
};