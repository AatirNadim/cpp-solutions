// problem link --> https://leetcode.com/problems/search-insert-position/

// my solution link --> https://leetcode.com/problems/search-insert-position/discuss/3210159/C%2B%2B-oror-Binary-Search-oror-Short-and-Simple

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int minval = 0, maxval = nums.size() - 1, medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(nums[medval] == target) return medval;
            if(nums[medval] < target) minval = medval + 1;
            else maxval = medval - 1;
        }
        return minval;
    }
};