// problem link --> https://leetcode.com/problems/jump-game/

// my solution link --> https://leetcode.com/problems/jump-game/discuss/2952482/C%2B%2B-oror-Greedy-Approach-oror-O(n)-time-oror-O(1)-space

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), idx = 0, curr = nums[0];
        while(idx < n-1) {
            if(nums[idx] > curr) curr = nums[idx];
            if(!curr) break;
            else curr--;
            idx++;
        }
        return idx == n-1;
    }
};