// problem link --> https://leetcode.com/problems/add-digits/

// my solution link --> https://leetcode.com/problems/add-digits/discuss/3456620/C%2B%2B-oror-Recursion-oror-No-brainer

class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        int sum = 0;
        while(num) {
            sum += num%10; num/=10;
        }
        return addDigits(sum);
    }
};