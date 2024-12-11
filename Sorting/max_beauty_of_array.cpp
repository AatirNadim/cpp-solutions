/*
    problem link --> https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
*/

class Solution {
    
    int findRight(vector<int>& nums, int left, int right, int val) {
        int minval = left, maxval = right, medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(nums[medval] <= val) minval = medval + 1;
            else maxval = medval - 1;
        }
        return minval - 1;
    }
    
    int findMaxLen(vector<int>& nums, int idx, int& k) {
        int rptr = findRight(nums, idx + 1, nums.size() -1, nums[idx] + 2*k);
        return max(0, rptr - idx + 1);
    }
    
public:

    /*
        instead of taking a pivot point and manipulating the elements around it,
        take the beginning of possible subarray since the subarray can be of even length
    */
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for(int i=0;i<n;i++) {
            res = max(res, findMaxLen(nums, i, k));
        }
        return res;
    }
};