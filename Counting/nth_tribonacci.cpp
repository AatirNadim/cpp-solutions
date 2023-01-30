// problem link --> https://leetcode.com/problems/n-th-tribonacci-number/

// my solution link --> https://leetcode.com/problems/n-th-tribonacci-number/discuss/3117159/C%2B%2B-oror-100-faster-oror-Short-and-Simple

class Solution {
public:
    int tribonacci(int n) {
        if(n < 2) return n;
        if(n == 2) return 1;
        int a = 0, b = 1, c = 1, d;
        n -= 2;
        while(n--) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};