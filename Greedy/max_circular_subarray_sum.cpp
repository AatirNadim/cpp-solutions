// problem link --> https://leetcode.com/problems/maximum-sum-circular-subarray/

// my solution link --> https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/3068547/C%2B%2B-oror-O(n)-time-oror-O(1)-space-oror-95-faster

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxval = nums[0], currmax = nums[0], sum = nums[0];
        int minval = nums[0], currmin = nums[0], n = nums.size();
        for(int i=1;i<n;i++) {
            if(currmax + nums[i] < nums[i]) currmax = nums[i];
            else currmax += nums[i];
            maxval = max(currmax, maxval);
            sum += nums[i];
            if(currmin + nums[i] > nums[i]) currmin = nums[i];
            else currmin += nums[i];
            minval = min(minval, currmin);
        }
        if(sum - minval) return max(maxval, sum - minval);
        return maxval;
    }
};