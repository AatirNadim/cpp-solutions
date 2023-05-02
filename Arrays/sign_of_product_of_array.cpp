// problem link --> https://leetcode.com/problems/sign-of-the-product-of-an-array/

// my solution link --> https://leetcode.com/problems/sign-of-the-product-of-an-array/discuss/3476350/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for(int& i : nums) {
            if(!i) return 0;
            if(i < 0) res = -res;
        }
        return res;
    }
};