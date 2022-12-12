// problem link --> https://leetcode.com/problems/climbing-stairs/

// my solution link --> https://leetcode.com/problems/climbing-stairs/discuss/2903813/C%2B%2B-oror-O(n)-time-oror-O(1)-space-oror-Linear-Traversal

class Solution {
public:
    int climbStairs(int n) {
        if(n < 4) return n;
        int a = 2, b = 3, c;
        for(int i=4;i<=n;i++) {
            c = a+ b;
            a = b; b = c;
        }
        return c;
    }
};