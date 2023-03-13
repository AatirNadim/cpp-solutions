// problem link --> https://leetcode.com/problems/house-robber/

// my solution link --> https://leetcode.com/problems/house-robber/discuss/2912095/C%2B%2B-oror-0ms-oror-95-less-memory-oror-Easy


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return *max_element(nums.begin(), nums.end());
        nums[2] += nums[0];
        for(int i=3;i<n;i++) {
            nums[i] += max(nums[i-2], nums[i-3]);
        }
        return max(nums[n-2], nums[n-1]);
    }
};