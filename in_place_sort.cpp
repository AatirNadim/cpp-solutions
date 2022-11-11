//Question link --> https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// this is a concise code of the solution, with arguably the simplest control flow.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), right = 1, left = 1;
        while(right < n) {
            while(right < n and nums[right] == nums[right - 1]) right++;
            if(right < n) nums[left++] = nums[right++];
        }
        return left;
    }
};