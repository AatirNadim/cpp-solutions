// problem link --> https://leetcode.com/problems/maximum-product-subarray/

// my solution link --> https://leetcode.com/problems/maximum-product-subarray/discuss/3201797/C%2B%2B-oror-O(n)-time-oror-O(1)-space

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minyet = 1, maxyet = 1, res = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(!nums[i]) {
                maxyet = 1, minyet = 1; 
                res = max(res, 0);
                continue;
            }
            int maxyet1 = max({maxyet*nums[i], minyet*nums[i], nums[i]});
            int minyet1 = min({maxyet*nums[i], minyet*nums[i], nums[i]});
            res = max(res, maxyet1);
            maxyet = maxyet1, minyet = minyet1;
        }
        return res;
        
    }
};